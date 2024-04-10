#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,x,y;
int lg[1005],fa[1005][20],dep[1005];
ll f[205],f2[205],sb[205][205];
vector<int> v[205];
ll ans;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

void dfs1(int x,int f){
	fa[x][0]=f;dep[x]=dep[f]+1;
	for(int i=1;i<=lg[dep[x]];i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(auto i:v[x]){
		if(i==f){continue;}
		dfs1(i,x);
	}
}

int lca(int x, int y) {
	if(dep[x]<dep[y]){swap(x, y);}
	while(dep[x]>dep[y]){x = fa[x][lg[dep[x]-dep[y]] - 1];}
	if(x == y) return x;
	for(int k = lg[dep[x]] - 1; k >= 0; --k)
		if(fa[x][k] != fa[y][k])
			x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}

void get(int x){
	memset(fa,0,sizeof(fa));
	memset(dep,0,sizeof(dep));
	dfs1(x,0);
	ll res=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			k=lca(i,j);
			res+=sb[dep[j]-dep[k]][dep[i]-dep[k]];
		}
	}
	ans=(ans+res)%M;
}

int main(){
	ll inv=M/2+1;
	for(i=1;i<=1000;i++){lg[i]=lg[i>>1]+1;}
	for(i=1;i<=200;i++){sb[0][i]=1;}
	for(i=1;i<=200;i++){
		for(j=1;j<=200;j++){
			sb[i][j]=(sb[i-1][j]+sb[i][j-1])*inv%M;
		}
	}
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		get(i);
	}
	ans=ans*ksm(n,M-2)%M;
	printf("%lld",ans);
}