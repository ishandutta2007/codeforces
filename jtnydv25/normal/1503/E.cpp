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
const int N = 4500;
int C[N][N];
int pref[N / 2][N / 2];
int pref2[N / 2][N / 2];
inline int f(int n, int l){
	if(l < 0) return 0;
	if(n == 0) return l == 0;
	return C[n + l - 1][n - 1];
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	for(int i = 0; i < N; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++){
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
		}
	}
	int n, m; cin >> n >> m;
	for(int L = 1; L <= n; L++){
		for(int b = 1; b < m; b++){
			pref[L][b] = add(pref[L][b - 1], mul(f(L, b), f(L + 1, m - b - 1)));
		}
	}

	for(int a = 1; a < m; a++){
		for(int i = 1; i <= n; i++){
			pref2[a][i] = add(pref2[a][i - 1], mul(f(i, a), f(n - i + 1, a - 1)));
		}
	}
	int ans = 0;
	for(int a = 1; a < m; a++){
		for(int l = 1; l < n; l++){
			int ways = mul(f(l, a), f(l + 1, m - a - 1));
			int L = n - l;
			int ways2 = sub(pref[L][m - 1], pref[L][m - a]);
			ans = add(ans, mul(ways, ways2));
			ways = mul(f(l, a), f(n - l + 1, a - 1));
			ans = add(ans, mul(ways, pref2[m - a][L]));
		}
	}
	cout << mul(2, ans) << endl;
}