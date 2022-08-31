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
const int mod = 31607;

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
const int N = 21;
int prod[N][1 << N];
int fst[1 << N];
int a[N][N];

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	for(int i = 1; i < (1 << n); i++){
		if(i & 1) fst[i] = 0;
		else fst[i] = fst[i / 2] + 1;
		// trace(i, fst[i]);
	}
	vector<int> col(n, 1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			a[i][j] = mul(a[i][j], inv(10000));
			col[j] = mul(col[j], a[i][j]);
		}
	}

	int total = (1 << n) - 1;
	int inv2 = inv(2), inv4 = inv(4), inv8 = inv(8), inv16 = inv(16);
	for(int i = 0; i < n; i++){
		prod[i][0] = 1;
		for(int j = 1; j < (1 << n); j++){
			int k = fst[j];
			prod[i][j] = mul(prod[i][j ^ (1 << k)], a[i][k]);
		}
	}
	int ans = 0;
	for(int u = 0; u < 2; u++){
		for(int v = 0; v < 2; v++){
			// if(u||v) continue;
			for(int mask = 0; mask < (1 << n); mask++){
				int p = 1;
				vector<int> rem(n, total ^ mask);
				for(int j = 0; j < n; j++) if(mask >> j & 1){
					p = mul(p, col[j]);
				}

				if(u){
					for(int j = 0; j < n; j++) if(rem[j] >> j & 1){
						p = mul(p, a[j][j]);
						rem[j] ^= 1 << j;
					}
				}
				if(v){
					// if(u==0&&v==1&&mask==1) trace(rem);
					for(int j = 0; j < n; j++){
						if(rem[j] >> (n - 1 - j) & 1){
							p = mul(p, a[j][n - 1 - j]);
							rem[j] ^= 1 << (n - 1 - j);
						}
					}
				}

				for(int j = 0; j < n; j++){
					p = mul(p, sub(1, prod[j][rem[j]]));
				}
				int cnt = u + v + __builtin_popcount(mask);
				if(cnt % 2 == 0) ans = add(ans, p);
				else ans = sub(ans, p);
			}
		}
	}
	cout << sub(1, ans) << endl;
}