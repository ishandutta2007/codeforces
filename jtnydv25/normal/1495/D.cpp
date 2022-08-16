#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

const int mod = 998244353;
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
const int N = 405;
int store[N][N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, m; cin >> n >> m;

	vector<vector<int>> adj(n);
	const int INF = 1 << 20;
	vector<vector<int>> D(n, vector<int>(n, INF));

	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		D[u][v] = D[v][u] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < n; i++) D[i][i] = 0;
	for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	}
	vector<int> nodes(n);
	iota(all(nodes), 0);
	vector<int> onPath(n, 0);
	vector<int> where(n);
	
	for(int x = 0; x < n; x++){
		sort(all(nodes), [&](int i, int j){return D[x][i] < D[x][j];});
		for(int y = 0; y < n; y++){
			if(y < x){
				cout << store[y][x] << " ";
				continue;
			}
			fill(all(onPath), 0);

			for(int j = 0; j < n; j++){
				if(D[x][j] + D[y][j] == D[x][y]) onPath[j] = 1;
			}
			
			if(accumulate(all(onPath), 0) != D[x][y] + 1){
				cout << (store[x][y] = 0) << " ";
				continue;
			}

			for(int i = 0; i < n; i++) if(onPath[i]){
				where[i] = D[x][i];
			}
			bool error = false;
			int ans = 1;
			for(int z : nodes){
				if(onPath[z]) continue;
				int d = D[x][z] + D[x][y] - D[y][z];
				if(d % 2 != 0 || d / 2 > D[x][y]){
					ans = 0;
					break;
				}
				where[z] = d / 2;
				int options = 0;
				for(int j : adj[z]) if(D[x][j] == D[x][z] - 1 && where[j] == where[z]){
					options++;
				}
				if(options == 0){
					ans = 0;
					break;
				}
				if(options != 1) ans = mul(ans, options);
			}
			cout << (store[x][y] = ans) << " ";
		}
		cout << endl;
	}
}