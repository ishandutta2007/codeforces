#include <bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
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
        for (res = 1; p; p >>= 1, Mul(a, a)) {
            if (p & 1) Mul(res, a);
        }
        return res;
    }
    inline int Inv(int a) { return ksm(a, mod - 2); }
}    using namespace modular;
#define pb push_back
#define rez resize
const int N = 1e5 + 5;
int n, m, a[N], ans[N];
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	for (int tt = read(); tt; --tt) {
		n = read(), m = read();
		for (int i = 1; i <= n; ++i) a[i] = read();
		if (n <= m) {
			for (int i = 1; i <= n; ++i) cout << 1;
			cout << '\n';
			continue;
		}
		int id = 0, vl = 0;
		for (int i = n; i; --i) {
			if (vl < a[i]) {
				if (vl < m) ++vl, ans[i] = 1;
				else ans[i] = 0;
			}
			else ans[i] = 1;
		}
		for (int i = 1; i <= n; ++i) cout << ans[i];
		cout << '\n';
	}
	return 0;
}