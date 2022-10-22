//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5;
struct Edge{int to,w,nxt;}e[2*maxn];
int cnt,head[maxn];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w){
	e[cnt]=(Edge){v,w,head[u]};
	head[u]=cnt++;
	return ;
}
ll dp1[maxn],dp2[maxn];
int bl[maxn];
void upd(ll &mx,ll &cx,int &bl,ll w,int b){
	if(w>mx)cx=mx,mx=w,bl=b;
	else cx=max(cx,w);
	return ;
}
void dfs1(int x,int fa){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs1(tmp,x);
		ll w=dp1[tmp]+e[i].w;
		upd(dp1[x],dp2[x],bl[x],w,tmp);
	}
	return ;
}
void dfs2(int x,int fa){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		ll w=e[i].w;
		if(bl[x]!=tmp)w+=dp1[x];else w+=dp2[x];
		upd(dp1[tmp],dp2[tmp],bl[tmp],w,x);
		dfs2(tmp,x);
	}
	return ;
}
int f[maxn][17];
void dfs(int x,int fa){
	f[x][0]=fa;
	for(int i=1;i<17;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x);
	}
	return ;
}
int b[maxn];
void Dfs(int x,int fa){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		Dfs(tmp,x);
		b[x]+=b[tmp];
	}
	return ;
}
int main(){
    int n;
	n=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v,w;
		u=read();v=read();w=read();
		add(u,v,w),add(v,u,w);
	}
	dfs1(1,0);dfs2(1,0);
	ll val=1e18;
	int p=0;
	for(int i=1;i<=n;i++)if(dp1[i]<val)p=i,val=dp1[i];
	dfs(p,0);
	int Q;
	Q=read();
	dp1[0]=-1e18;
	while(Q--){
		ll lim;
		lim=read();
		for(int i=1;i<=n;i++){
			int x=i;
			for(int j=16;j>=0;j--)if(dp1[i]-dp1[f[x][j]]<=lim)x=f[x][j];
			b[i]++,b[f[x][0]]--;
		}
		Dfs(p,0);
		int res=0;
		for(int i=1;i<=n;i++)res=max(res,b[i]),b[i]=0;
		printf("%d\n",res);
	}
    return 0;
}