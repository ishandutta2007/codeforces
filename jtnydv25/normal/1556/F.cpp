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

int p[20][20];
int a[20];

int probSCC[1 << 14];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems

	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j < i; j++){
			p[i][j] = mul(a[i], inv(a[i] + a[j]));
			p[j][i] = mul(a[j], inv(a[i] + a[j]));
		}
	}
	for(int i = 1; i < (1 << n); i++){
		probSCC[i] = 1;
		for(int j = i; j; j = (j - 1) & i){
			if(j == i) continue;
			int prob = 1;
			int _j = i ^ j;
			for(int u = 0; u < n; u++) if(j >> u & 1){
				for(int v = 0; v < n; v++) if(_j >> v & 1){
					prob = mul(prob, p[u][v]);
				}
			}
			probSCC[i] = sub(probSCC[i], mul(probSCC[j], prob));
		}
	}

	int ans = 0;
	int i = (1 << n) - 1;
	for(int j = i; j; j = (j - 1) & i){
		int prob = probSCC[j];
		int _j = i ^ j;
		for(int u = 0; u < n; u++) if(j >> u & 1){
			for(int v = 0; v < n; v++) if(_j >> v & 1){
				prob = mul(prob, p[u][v]);
			}
		}
		ans = add(ans, mul(__builtin_popcount(j), prob));
	}
	cout << ans << endl;
}