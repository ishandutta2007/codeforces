#include <cstdio>
#include <vector> 
#include <algorithm>

int n,head[1000001],nxt[2000001],b[2000001],k,mxdep[1000010],num[1000010],top,d[1000010];
std::vector<int>tem;
std::vector<std::pair<int,int> >vec[1000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int dia;
void dfs(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			dia=std::max(dia,mxdep[x]+mxdep[b[i]]+1);
			mxdep[x]=std::max(mxdep[x],mxdep[b[i]]+1);
		}
}
int ans[500010],ans2[500010];
void Do(int a,int b){
	int sa=vec[a].size(),sb=vec[b].size(),ind=0;
	for(int i=0;i<sa;i++){
		while(ind<sb&&vec[b][ind].first<vec[a][i].first)++ind;
		if((vec[a][i].first<<1)<=n&&ind<sb-1)ans2[vec[a][i].first<<1]=std::max(ans2[vec[a][i].first<<1],vec[a][i].second+vec[b][ind].second-2);
	}
	ind=0;
	for(int i=0;i<sb;i++){
		while(ind<sa&&vec[a][ind].first<vec[b][i].first)++ind;
		if((vec[b][i].first<<1)<=n&&ind<sa-1)ans2[vec[b][i].first<<1]=std::max(ans2[vec[b][i].first<<1],vec[b][i].second+vec[a][ind].second-2);
	}
}
void getdis(int x,int f,int len){
	int mx=-1,skdmx=-1;
	top=0;
	tem.clear();
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			if(mx<mxdep[b[i]]+1)skdmx=mx,mx=mxdep[b[i]]+1;
			else skdmx=std::max(skdmx,mxdep[b[i]]+1);
			tem.push_back(mxdep[b[i]]+1);
		}
	if(f)tem.push_back(len);
	std::sort(tem.begin(),tem.end());
	int sz=tem.size();
	for(int i=0;i<sz;i++){
		if(!i||tem[i]!=tem[i-1])vec[x].push_back(std::make_pair(tem[i],sz-i));
	}
	sz=vec[x].size();
	for(int i=0;i<sz;i++){
//		printf("%d %d %d\n",x,vec[x][i].first,vec[x][i].second);
		if((vec[x][i].first<<1)<=n){
			ans[vec[x][i].first<<1]=std::max(ans[vec[x][i].first<<1],vec[x][i].second);
			if(i<sz-1)ans[vec[x][i].first<<1|1]=std::max(ans[vec[x][i].first<<1|1],vec[x][i+1].second+1);
		}
	}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			getdis(b[i],x,std::max(std::max(len,0),((mxdep[b[i]]+1)==mx)?skdmx:mx)+1);
			Do(x,b[i]);
		}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u),++d[u],++d[v];
	dfs(1,0);
	getdis(1,0,0);
	ans[n+1]=1;
	ans[dia]=std::max(ans[dia],2);
	for(int i=n;i;i--)ans2[i]=std::max(ans2[i+2],ans2[i]);
	for(int i=n;i;i--)ans[i]=std::max(ans[i+1],ans[i]);
	for(int i=1;i<=n;i++)ans[1]=std::max(ans[1],d[i]+1);
	for(int i=1;i<=n;i++)printf("%d ",(i==1)?ans[i]:std::max(ans[i],ans2[i]));
}