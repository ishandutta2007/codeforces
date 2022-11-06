#include <bits/stdc++.h>
using namespace std;
#define gc getchar
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
typedef long long ll;
inline ll readl() {
	static ll ans;
	static int f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
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
		static int res;
		for (res = 1; p; p >>= 1, Mul(a, a)) if (p & 1) Mul(res, a);
		return res;
	}
}	using namespace modular;
typedef pair <int, ll> pil;
typedef double db;
#define fi first
#define se second
#define pb push_back
#define rez resize
#define ppp pop_back
const int N = 2e5 + 5;
int n, x, a[N];
inline int Abs(int x) { return x < 0 ? -x : x; }
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	for (int tt = read(); tt; --tt) {
		n = read(), x = read();
		for (int i = 1; i <= n; ++i) a[i] = read();
		int res = 0;
		for (int l = 1, r = 0, mx, mn; l <= n; l = r + 1) {
			++res;
			mx = mn = a[l];
			while (r < n) {
				mx = max(mx, a[r + 1]);
				mn = min(mn, a[r + 1]);
				if (Abs(mx - a[r + 1]) <= x * 2 && Abs(mn - a[r + 1]) <= x * 2) ++r;
				else break;
			}
		}
		cout << max(0, res - 1) << '\n';
	}
	return 0;
}