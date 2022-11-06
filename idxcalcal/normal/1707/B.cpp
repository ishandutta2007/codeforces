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
int n, a[N], b[N];
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	for (int tt = read(); tt; --tt) {
		n = read();
		int ct = 0, prect = 0;
		for (int i = 1, x; i <= n; ++i) {
			x = read();
			if (!x) ++ct;
			else a[++prect] = x;
		}
		n = prect;
		prect = ct;
		while (n + prect > 1) {
			if (!n) break;
			ct = prect - 1;
			prect = 0;
			if (ct != -1) b[++prect] = a[1];
			else ct = 0;
			for (int i = 1, x; i < n; ++i) {
				x = a[i + 1] - a[i];
				if (!x) ++ct;
				else b[++prect] = x;
			}
			sort(b + 1, b + prect + 1);
			n = prect;
			for (int i = 1; i <= n; ++i) a[i] = b[i];
			prect = ct;
			if (!n) break;
		}
		if (n) cout << a[1] << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}