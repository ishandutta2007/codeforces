// Hydro submission #622f34d18f1b401e9d3ff49c@1648465851327
#include <bits/stdc++.h>
#define forn(i,s,t) for(int i = (s); i <= (t); ++i)
#define form(i,s,t) for(int i = (s); i >= (t); --i)
#define rep(i,s,t) for(int i = (s); i < (t); ++i)
using namespace std;
typedef unsigned long long u64;
const int N = 2e5 + 3, Mod = 998244353;
struct Mint {
	int res;
	Mint() {res = 0;}
	Mint(int a) : res(a) {}
	friend Mint operator + (Mint A, Mint B) {
		return Mint((A.res + B.res >= Mod) ? (A.res + B.res - Mod) : (A.res + B.res));
	}
	friend Mint& operator += (Mint& A, Mint B) {return A = A + B;}
	friend Mint operator - (Mint A, Mint B) {B.res = Mod - B.res; return A + B;}
	friend Mint operator - (Mint A) {return Mint(Mod - A.res);}
	friend Mint operator + (Mint A) {return A;}
	friend Mint& operator -= (Mint& A, Mint B) {return A = A - B;}
	friend Mint operator * (Mint A, Mint B) {return 1ll * A.res * B.res %Mod;}
	friend Mint& operator *= (Mint& A, Mint B) {return A = A * B;}
	friend Mint operator ~ (Mint A) {
		static Mint res; res = Mint(1);
		static int k; k = Mod - 2;
		for(;k;k>>=1, A*=A) (k&1) && (res = res * A, 0);
		return res;
	}
	friend Mint operator / (Mint A, Mint B) {return A * (~B);}
	friend Mint& operator /= (Mint& A, Mint B) {return A *= (~B);}
	friend Mint operator >> (Mint A, Mint B) {return Mint(A.res / B.res);}
	friend Mint& operator >>= (Mint& A, Mint B) {return A = A>>B;}
	inline void Div2() {res = res + (res & 1) * Mod >> 1;}
} ;
int n; vector<int> T[N]; Mint f[3][N], g[3];
void dfs(int u) {
	if (!T[u].size()) { f[2][u] = Mint(1); return ; }
	f[0][u] = Mint(1);
	for (const int& v : T[u]) {
		dfs(v);
		rep (i, 0, 3) g[i] = f[i][u], f[i][u] = Mint(0);
		f[0][u] = g[0] * (f[0][v] + f[2][v]);
		f[1][u] = g[0] * (f[1][v] + f[2][v]) + g[1] * (f[0][v] + f[2][v]);
		f[2][u] = g[1] * (f[1][v] + f[2][v]) + g[2] * (f[0][v] + f[1][v] + Mint(2) * f[2][v]);
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	forn (i, 2, n) {
		int x; cin >> x;
		T[x].push_back(i);
	}
	dfs(1);
//	forn (i, 1, n) cout << f[0][i].res << " \n"[i == n];
//	forn (i, 1, n) cout << f[1][i].res << " \n"[i == n];
//	forn (i ,1, n) cout << f[2][i].res << " \n"[i == n];
	cout << (f[0][1] + f[2][1]).res << '\n';
	return 0;
}