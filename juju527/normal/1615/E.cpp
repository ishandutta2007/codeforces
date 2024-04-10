#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=2e5+5;
struct Edge{int to,nxt;}e[2*maxn];
int cnt;
int head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
	e[cnt]=(Edge){v,head[u]};
	head[u]=cnt++;
	return ;
}
int dep[maxn];
int leaf[maxn],len[maxn];
pair<int,int> x[maxn];
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;leaf[x]=x;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs1(tmp,x);
		if(dep[leaf[x]]<dep[leaf[tmp]])leaf[x]=leaf[tmp];
	}
	return ;
}
ll f[maxn];
int main(){
	int n,k;
	n=read();k=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v),add(v,u);
	}
	dfs1(1,0);
	for(int i=1;i<=n;i++)len[leaf[i]]=max(len[leaf[i]],dep[leaf[i]]-dep[i]+1);
	int m=0;
	for(int i=1;i<=n;i++)if(leaf[i]==i)x[++m]=make_pair(len[i],i);
	sort(x+1,x+m+1);
	f[0]=0;
	for(int i=1;i<=n;i++)f[i]=min(f[i-1],1ll*i*(i-n));
	ll res=f[n],sum=0;
	for(int i=m;i>=1;i--){
		int r=m-i+1;
		sum+=x[i].fi;
		if(r<=k)res=max(res,1ll*r*(n-r)+f[n-sum]);
	}
	for(int r=m+1;r<=min(n,k);r++)res=max(res,1ll*r*(n-r)+f[0]);
	printf("%lld\n",res);
	return 0;
}