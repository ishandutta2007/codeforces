#include <cstdio>
#include <vector>
#include <algorithm>

using std::min;

int head[500001],nxt[1000001],b[1000001],k,h[500001],K,s[500001],n,orig[500010],st[500010][21],lim,loga[500001],v[500001],gp[500001];
std::vector<int>vec[500001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
bool Assert(int l,int r,int val){
	if(l>r)return 1;
	int k=loga[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k])>=val;
}
int getpos(int x){return std::upper_bound(orig+1,orig+lim+2,x)-orig-1;}
void dfs(int x,int f,int mn,int skdmn,int mnpos){
	if(mn>h[x])skdmn=mn,mn=h[x],mnpos=x;
	else if(skdmn>h[x])skdmn=h[x];
	vec[mnpos].push_back(skdmn);
	++st[gp[x]=getpos(v[x]=mn)][0];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x,mn,skdmn,mnpos);
}
bool judge(int u){
	for(int i=1;i<=n;i++){
		if(vec[i].empty())continue;
		bool cando=1;
		int last=0x7f7f7f7f+1,disc=lim,tem;
		for(int j=vec[i].size();j;--j)
			if(min(vec[i][j-1],v[i]+u)!=last){
				cando&=Assert((tem=getpos(min(vec[i][j-1],v[i]+u)))+1,disc,j-vec[i].size());
				last=min(vec[i][j-1],v[i]+u),disc=tem;
			}
		cando&=Assert(gp[i]+1,disc,-vec[i].size());
		cando&=Assert(1,gp[i],0);
		if(cando)return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",h+i);
	for(int i=1,s,t;i<n;i++)scanf("%d%d",&s,&t),push(s,t),push(t,s);
	scanf("%d",&K);
	for(int i=1;i<=K;i++)scanf("%d",s+i),orig[i]=s[i];
	std::sort(orig+1,orig+K+1);
	lim=std::unique(orig+1,orig+K+1)-orig-1;
	orig[lim+1]=0x7f7f7f7f+1;
	for(int i=1;i<=K;i++)--st[getpos(s[i])][0];
	dfs(1,0,0x7f7f7f7f,0x7f7f7f7f,0);
	for(int i=lim-1;i;i--)st[i][0]+=st[i+1][0];
	for(int i=1;i<=n;i++)std::sort(vec[i].begin(),vec[i].end());
	loga[0]=-1;
	for(int i=1;i<=n;i++)loga[i]=loga[i>>1]+1;
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=lim;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	int l=0,r=1000000000,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}