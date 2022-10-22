#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
int n,f[110000][2],g[110000][2][2];
vector<int> vec[110000];
void dfs(int u){
	for (int v:vec[u]) dfs(v);
	g[u][0][0]=1; g[u][0][1]=1;
	f[u][1]=1;
	for (int v:vec[u]){
		int t0=(1ll*f[u][0]*f[v][0]+1ll*f[v][1]*f[u][1])%Mod;
		int t1=(1ll*f[u][0]*f[v][1]+1ll*f[v][0]*f[u][1])%Mod;
		f[u][0]=(f[u][0]+t0)%Mod; f[u][1]=(f[u][1]+t1)%Mod;
		int t00=1ll*g[u][0][0]*f[v][0]%Mod;
		int t01=1ll*g[u][1][1]*f[v][1]%Mod;
		int t11=1ll*g[u][0][1]*f[v][1]%Mod;
		g[u][0][0]=(g[u][0][0]+t00)%Mod;
		g[u][0][1]=(g[u][0][1]+t01)%Mod;
		g[u][1][1]=(g[u][1][1]+t11)%Mod;
	}
	f[u][0]=(2ll*f[u][0]-g[u][1][1]+Mod)%Mod;
	f[u][1]=(2ll*f[u][1]-g[u][0][0]+Mod)%Mod;
}
int main(){
	scanf("%d",&n); int u;
	for (int i=2;i<=n;i++){
		scanf("%d",&u);
		vec[u].push_back(i);
	}
	dfs(1);
	printf("%d\n",(f[1][0]+f[1][1])%Mod);
    return 0;
}