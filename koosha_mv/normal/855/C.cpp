#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define maxn 100002
#define pb push_back
#define mod 1000000007
#define MEMSET(x) memset(x,0,sizeof(x))
using namespace std;
int n,m,k,x;
vector<int> ke[maxn];
int f[maxn][13][3],temp[13][3];
int add(int x, int y){
	return (x+y) % mod;
}
int mul(int x, int y){
	return ( (ll)(x)* y)% mod;
}
int bfs(int u, int p){
	f[u][0][0]=k-1;
	f[u][1][1] = 1;
	f[u][0][2] = m-k;
	for(int &v:ke[u]){
		if(v==p) continue;
		bfs(v,u);
		For(i,0,x) For(j,0,2) {
			temp[i][j] = f[u][i][j];
			f[u][i][j] = 0;
		}
		For(i,0,x) For(j,0,x-i){
			int t = i+j;
			f[u][t][0] = add(f[u][t][0],mul(temp[i][0],add(f[v][j][0],add(f[v][j][1],f[v][j][2]))));
			f[u][t][1] = add(f[u][t][1],mul(temp[i][1],f[v][j][0]));
			f[u][t][2] = add(f[u][t][2],mul(temp[i][2],add(f[v][j][0],f[v][j][2])));
		}
	}
}
int main(){
	int u,v;
	cin >> 	n >> m;
	For(i,1,n-1){
		scanf("%d%d",&u,&v);
		ke[u].pb(v);
		ke[v].pb(u);
	}
	cin >> k >> x;
	bfs(1,1);
	int ans = 0;
	For(i,0,x){
		ans=  add(ans,f[1][i][0]);
		ans=  add(ans,f[1][i][2]);
		ans=  add(ans,f[1][i][1]);
	}
	cout << ans;
}