#include <bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define ppp pop_back
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;
typedef vector <int> poly;
namespace modular {
	const int mod = 998244353;
	inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
	inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return (ll) a * b % mod; }
	inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
	inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
	inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
	inline int ksm(int a, int p) {
		static int ret;
		for (ret = 1; p; p >>= 1, Mul(a, a)) {
			(p & 1) && (Mul(ret, a), 1);
		}
		return ret;
	}
	inline int Inv(int a) { return ksm(a, mod - 2); }
	inline int sqr(int x) { return mul(x, x); }
	inline int cub(int x) { return mul(mul(x, x), x); }
}	using namespace modular;
#define gc getchar
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
inline ll readl() {
	static ll ans;
	static int f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
const int N = 2e5 + 5;
int n, a[N], b[N];
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	for (ri tt = read(); tt; --tt) {
		n = read();
		for (ri i = 1; i <= n; ++i) a[i] = read();
		int x = -1, y = -1;
		for (ri i = 1, j = n; i < j; ++i, --j) {
			if (a[i] == a[j]) continue;
			else {
				x = a[i];
				y = a[j];
				break;
			}
		}
		if (x == -1 && y == -1) {
			puts("YES");
			continue;
		}
		for (ri i = 1; i <= n; ++i) b[i] = a[i];
		bool ff = 0, fff;
		int m = 0;
		for (ri i = 1; i <= n; ++i) if (b[i] != x) a[++m] = b[i];
		fff = 1;
		for (ri i = 1, j = m; i < j; ++i, --j) {
			if (a[i] != a[j]) {
				fff = 0;
				break;
			}
		}
		if (fff) {
			puts("YES");
			continue;
		}
		m = 0;
		for (ri i = 1; i <= n; ++i) if (b[i] != y) a[++m] = b[i];
		fff = 1;
		for (ri i = 1, j = m; i < j; ++i, --j) {
			if (a[i] != a[j]) {
				fff = 0;
				break;
			}
		}
		if (fff) {
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}