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
#define endl '\n'
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

const int N = 505;
int a[2 * N][N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> x(2 * n, -1);
		vector<vector<int>> c;
		vector<bool> done;
		for(int i = 0; i < 2 * n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
				a[i][j]--;
			}
		}

		for(int j = 0; j < n; j++){
			vector<vector<int>> T(n);
			for(int i = 0; i < 2 * n; i++) T[a[i][j]].push_back(i);
			for(int i = 0; i < n; i++) if(!T[i].empty()){
				c.push_back(T[i]);
				done.push_back(0);
			}
		}
		int k = c.size();
		function<void()> fixAll = [&](){
			for(int i = 0; i < k; i++) if(!done[i]){
				int h = -1;
				for(int j : c[i]){
					if(x[j] == 1){
						h = j;
						break;
					}
				}
				if(h != -1){
					for(int j : c[i]) if(j != h){
						x[j] = 0;
					}
					done[i] = true;
				}
			}
		};
		vector<vector<int>> adj(2 * n);
		while(true){
			// can you find a singleton?
			fixAll();
			bool found = false;
			for(int i = 0; i < k; i++) if(!done[i]){
				int r = -1;
				int cnt = 0;
				for(int j : c[i]){
					if(x[j] == -1){
						cnt++;
						r = j;
					}
				}
				if(cnt == 1){
					x[r] = 1;
					found = true;
					break;
				}
			}
			if(!found){
				for(int i = 0; i < k; i++) if(!done[i]){
					int p = -1, q = -1;
					int cnt = 0;
					for(int j : c[i]){
						if(x[j] == -1){
							cnt++;
							if(p == -1){
								p = j;
							} else q = j;
						}
					}
					adj[p].push_back(q);
					adj[q].push_back(p);
				}
				break;
			}
		}

		function<void(int, int)> dfs = [&](int s, int c){
			x[s] = c;
			for(int v : adj[s]) if(x[v] == -1){
				dfs(v, c ^ 1);
			}
		};
		int comp = 0;
		for(int i = 0; i < 2 * n; i++) if(x[i] == -1){
			comp++;
			dfs(i, 0);
		}
		cout << powr(2, comp) << endl;
		for(int i = 0; i < 2 * n; i++) if(x[i] == 1){
			cout << i + 1 << " ";
		}
		cout << endl;
	}
}