#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ppp pop_back
#define rez resize
using namespace std;
typedef long long ll;
namespace modular {
	const int mod = 998244353;
	inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
	inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return (ll) a * b % mod; }
	inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b;  }
	inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
	inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
	inline int ksm(int a, int p) {
		static int res;
		for (res = 1; p; p >>= 1, Mul(a, a)) {
			if (p & 1) Mul(res, a);
		}
		return res;
	}
	inline int Inv(int a) { return ksm(a, mod - 2); }
	inline int cal(int x) { return (ll) x * (x + 1) / 2 % mod; }
}	using namespace modular;
#define gc getchar
inline int read() {
	static int ans, f;
	static char ch;
	for (ch = gc(), f = 1; !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
inline ll readl() {
	static ll ans;
	static int f;
	static char ch;
	for (ch = gc(), f = 1; !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
#define fi first
#define se second
const int N = 2e5 + 5;
int n, a[N], b[N];
inline bool chk(int w) {
	int ct = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < ct) continue;
		if (ct + 1 + b[i] < w) continue;
		++ct;
		if (ct == w) return 1;
	}
	return 0;
}
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);;
	#endif
	for (int tt = read(); tt; --tt) {
		n = read();
		for (int i = 1; i <= n; ++i) {
			b[i] = read();
			a[i] = read();
		}
		int l = 1, r = n, res = 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (chk(mid)) l = mid + 1, res = mid;
			else r = mid - 1;
		}
		cout << res << '\n';
	}
	return 0;
}