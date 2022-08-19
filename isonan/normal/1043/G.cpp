#include <set>
#include <cstdio>
#include <algorithm>

int n,q,Loga[200010],toR[200010],toL[200010],far[200010],last[200010],nxt[200010],pos[26],mn[200010];
bool vis[26];
std::set<int>exiL,exiR;
char str[200010];
struct sa{
	int tax[2000001],tp[2000001],sa[2000001],rank[2000001],m,str[200010];
	int height[200010],st[200010][21];
	void Qsort(){
		for(int i=0;i<=m;i++)tax[i]=0;
		for(int i=1;i<=n;i++)++tax[rank[i]];
		for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
		for(int i=n;i;i--)sa[tax[rank[tp[i]]]--]=tp[i];
	}
	void Ssort(){
		m=1000;
//		for(int i=1;i<=n;i++)printf("%d ",rank[i]);putchar('\n');
		for(int i=1;i<=n;i++)tp[i]=i,str[i]=rank[i];
		Qsort();
		for(int w=1,p=1;p<n;m=p,w<<=1){
			p=0;
			for(int i=1;i<=w;i++)tp[++p]=n-w+i;
			for(int i=1;i<=n;i++)if(sa[i]>w)tp[++p]=sa[i]-w;
			Qsort();
			std::swap(rank,tp);
			rank[sa[1]]=p=1;
			for(int i=2;i<=n;i++)
				rank[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
		}
		for(int i=1;i<=n;i++)rank[sa[i]]=i;
		for(int i=1,k=0;i<=n;i++){
			if(k)--k;
			if(rank[i]==1){
				k=0;
				continue;
			}
			while(str[i+k]==str[sa[rank[i]-1]+k])++k;
			height[rank[i]]=st[rank[i]][0]=k;
		}
		for(int j=1;j<=20;j++)
			for(int i=1;i+(1<<j)-1<=n;i++)
				st[i][j]=std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int query(int l,int r){
//		printf("query %d %d\n",l,r);
		l=rank[l],r=rank[r];
		if(l>r)std::swap(l,r);
		++l;
		int k=Loga[r-l+1];
		return std::min(st[l][k],st[r-(1<<k)+1][k]);
	}
}pre,suf;
void upd(int l,int r,int x){
//	printf("%d %d %d\n",l,r,x);
	r-=(x<<1)-1;
	for(;;){
		int now=*exiR.lower_bound(l);
		if(now>r)break;
		exiR.erase(now);
		toR[now]=x;
	}
	r+=(x<<1)-1;
	l+=(x<<1)-1;
	for(;;){
		int now=*exiL.lower_bound(l);
		if(now>r)break;
		exiL.erase(now);
		toL[now]=x;
	}
}
const int block=450;
bool border(int l,int r){
	for(int i=1;i<=block&&(i<<1)<=r-l+1;i++)
		if(suf.query(n-r+1,n-l-i+2)>=i)return 1;
	for(int i=1;i<=block;i++){
		if(suf.rank[n-r+1]-i>0){
			int v=n-suf.sa[suf.rank[n-r+1]-i]+1;
			if(v>=l&&v<r&&((v-l+1)<<1)<=r-l+1&&suf.query(n-r+1,n-v+1)>=v-l+1)return 1;
		}
		if(suf.rank[n-r+1]+i<=n){
			int v=n-suf.sa[suf.rank[n-r+1]+i]+1;
			if(v>=l&&v<r&&((v-l+1)<<1)<=r-l+1&&suf.query(n-r+1,n-v+1)>=v-l+1)return 1;
		}
	}
	return 0;
}
int solve(int l,int r){
	if(r-l+1<=26){
		for(int i=0;i<26;i++)vis[i]=0;
		bool cando=0;
		for(int i=l;i<=r;i++){
			if(vis[str[i]-'a'])cando=1;
			vis[str[i]-'a']=1;
		}
		if(!cando)return -1;
	}
	for(int i=1;i*i<=r-l+1;i++)
		if((r-l+1)%i==0){
			if(pre.query(l,l+i)+i>=r-l+1)return 1;
			if(i>1&&pre.query(l,l+(r-l+1)/i)+(r-l+1)/i>=r-l+1)return 1;
		}
	if((toR[l]&&(toR[l]<<1)<=r-l+1)||(toL[r]&&(toL[r]<<1)<=r-l+1)||border(l,r))return 2;
	if(nxt[l]<=r||last[r]>=l||mn[l]<=r)return 3;
	return 4;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%s%d",&n,str+1,&q);
	for(int i=1;i<=n+1;i++)exiL.insert(i),exiR.insert(i);
	Loga[0]=-1;
	for(int i=1;i<=n;i++)Loga[i]=Loga[i>>1]+1;
	for(int i=1;i<=n;i++)pre.rank[i]=suf.rank[n-i+1]=str[i]-'a'+1;
	pre.Ssort();
	suf.Ssort();
	for(int i=1;i<=n;i++)
		for(int j=i;j+i<=n;j+=i){
			int L=pre.query(j,j+i),R=suf.query(n-j+1,n-j-i+1);
//			printf("%d %d %d %d\n",j,i,L,R);
			if(L+R-1>=i)upd(j-R+1,j+i+L-1,i);
		}
	for(int i=n;i;i--){
		far[i]=i;
		if(toR[i]){
			far[i]=i+toR[i];
			if(toR[i+toR[i]]==toR[i])far[i]=far[i+toR[i]];
		}
	}
	for(int i=1;i<=n;i++){
		last[i]=pos[str[i]-'a'];
		pos[str[i]-'a']=i;
	}
	for(int i=0;i<26;i++)pos[i]=n+1; 
	for(int i=n;i;i--){
		nxt[i]=pos[str[i]-'a'];
		pos[str[i]-'a']=i;
	}
	mn[n+1]=0x7f7f7f7f;
	for(int i=n;i;i--){
		mn[i]=mn[i+1];
		if(toR[i])mn[i]=std::min(mn[i],i+(toR[i]<<1)-1);
	}
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
//		printf("%d\n",border(l,r));
		printf("%d\n",solve(l,r));
	}
}