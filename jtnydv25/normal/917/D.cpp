#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

const int N = 105;
vector<int> con[N];

int dp[N][N][N];
int tree[N];
int dp2[N][N];
int dp3[N][N];
int ans[N][N][N];
int C[N][N];
int n;
void dfs(int s = 1, int p = 0){
	memset(dp2, 0, sizeof dp2);
	tree[s] = 1;
	for(int v : con[s]){
		if(v != p){
			dfs(v, s);
			tree[s] += tree[v];
		}
	}
	memset(dp2, 0, sizeof dp2);
	dp2[1][0] = 1;
	int currj = 1;
	int currk = 0;
	for(int v : con[s]){
		if(v != p){
			memset(dp3, 0, sizeof dp3);
			for(int j = 1; j <= currj; j++){
				for(int k = 0; k <= currk; k++){
					int currways = dp2[j][k];
					for(int j1 = 1; j1 <= tree[v]; j1++){
						for(int k1 = 0; k1 < tree[v]; k1++){							
							int ways = dp[v][j1][k1];
							// take
							dp3[j + j1][k + k1 + 1] = add(dp3[j + j1][k + k1 + 1], mul(ways, currways));
							// don't take
							dp3[j][k + k1] = add(dp3[j][k + k1], mul(ans[v][j1][k1], currways));
							// if(s == 2) cerr << j1 << " " << k1 << " " << " dp3[1][0] << endl;
						}
					}
				}
			}
			memcpy(dp2, dp3, sizeof dp3);
			currj += tree[v];
			currk += tree[v];
		}
	}
	// if(s == 2) cerr << s << " " << dp2[1][0] << endl;	
	// isf(s <= 3) cerr << s << " " << dp2[1][0] << " "<< dp2[2][0] << " " << dp2[3][0] << " " << dp2[4][0] << endl;
	for(int j = 1; j <= tree[s]; j++)
		for(int k = 0; k < tree[s]; k++){
			dp[s][j][k] = dp2[j][k];
			ans[s][j][k] = mul(dp[s][j][k], mul(n, j));
		}
}
int g[N], f[N];
int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		// u = i; v = i + 1;
		con[u].push_back(v);
		con[v].push_back(u);
	}
	for(int i = 0; i < N; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}
	dfs();
	for(int k = 0; k < n; k++){
		int ret = 0;
		for(int j = 1; j <= n; j++) ret = add(ret, ans[1][j][k]);
		g[k] = mul(inv(n * n), ret);
		if(k == n - 1) g[k] = 1;
		// cerr << k << " " << g[k] << endl;
	}
	for(int k = 0; k < n; k++){
		int ret = 0;
		for(int j = k; j < n; j++){
			int val = mul(g[j], C[j][k]);
			if((j - k) & 1){
				ret = sub(ret, val);
			}
			else ret = add(ret, val);
		}
		cout << ret << " ";
	}
}