#include <bits/stdc++.h>
using namespace std;
#define gc getchar
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : - ans;
}
const int N = 1e6 + 5, mod = 998244353;
int n, m, a[N];
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	for (int tt = read(); tt; --tt) {
	    n = read(), m = read();
	    bool ff = 1;
	    int mt = 1;
	    for (int i = 1; i <= n; ++i) {
	        a[i] = read();
	        if (i >= n - m + 1 && a[i] > 0) ff = 0;
	        if (i <= m) mt = (long long) mt * i % mod;
	        else {
	            if (a[i - m] == -1) mt = (long long) mt * i % mod;
	            else if (a[i - m] == 0) mt = (long long) mt * (m + 1) % mod;
	        }
	    }
	    if (!ff) cout << 0 << '\n';
	    else cout << mt << '\n';
	}
	return 0;
}