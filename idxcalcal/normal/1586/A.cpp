#include <bits/stdc++.h>
#define ri register int
#define pb push_back
#define rez resize
#define ppp pop_back
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
typedef long long ll;
inline ll readl() {
	static ll ans;
	static int f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
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
		for (ret = 1; p; p >>= 1, Mul(a, a)) (p & 1) && (Mul(ret, a), 1);
		return ret;
	}
}	using namespace modular;
const int N = 1e5 + 5;
int n, a[N];
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	for (ri tt = read(); tt; --tt) {
		n = read();
		int ss = 0;
		for (ri i = 1; i <= n; ++i) ss += (a[i] = read());
		bool ff = 0;
		for (ri i = 2; i * i <= ss; ++i) if (ss % i == 0) {
			ff = 1;
			break;
		}
		if (ff) {
			cout << n << '\n';
			for (ri i = 1; i <= n; ++i) cout << i << ' ';
			cout << '\n';
			continue;
		}
		bool FF = 1;
		for (ri i = 1; i <= n; ++i) {
			ss -= a[i];
			bool fff = 0;
			for (ri j = 2; j * j <= ss; ++j) {
				if (ss % j == 0) {
					fff = 1;
					break;
				}
			}
			if (fff) {
				FF = 0;
				cout << n - 1 << '\n';
				for (ri t = 1; t <= n; ++t) {
					if (i != t) cout << t << ' ';
				}
				cout << '\n';
				break;
			}
			ss += a[i];
		}
	}
	return 0;
}