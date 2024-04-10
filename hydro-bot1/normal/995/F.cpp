// Hydro submission #62f461c6326b9176d6dcc67d@1660182983319
#include <cstdio>
#include <vector>
#include <iostream>
#define LL long long
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 0; char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
	for(; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
	if(f) x = ~x + 1;
}
const int N = 3010;
const LL P = 1e9 + 7;
int n, d, m;
int f[N][N << 1];
int y[N << 1];
vector <int> G[N];
void dfs(int u) {
	for(int i = 1; i <= m; ++i) f[u][i] = 1;
	for(auto v : G[u]) {
		dfs(v);
		for(int i = m; i ; --i)
			f[u][i] = 1ll * f[u][i] * f[v][i] % P;
	}
	for(int i = m - 1; i ; --i) f[u][i] = (f[u][i] + f[u][i + 1]) % P;
}
LL fpow(LL x, int pnt = P - 2) {
	LL res = 1;
	for(; pnt; pnt >>= 1, x = x * x % P) if(pnt & 1) res = res * x % P;
	return res;
}
int Lagrange(int x) {
	if(1 <= x && x <= m) return y[x];
	LL res = 0;
	for(int i = 1; i <= m; ++i) {
		LL p = y[i], q = 1;
		for(int j = 1; j <= m; ++j) 
			if(i ^ j) p = p * (x - j) % P, q = q * (i - j) % P;
		res = (res + p * fpow(q)) % P;
	}
	return res;
}
int main() {
	read(n), read(d);
	for(int i = 2, u; i <= n; ++i) {
		read(u);
		G[u].emplace_back(i);
	}
	m = n + 1;
	dfs(1);
	for(int i = 1; i <= m; ++i) y[m - i + 1] = f[1][i];
	printf("%d\n",Lagrange(d));
}