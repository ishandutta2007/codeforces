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
const int N = 5e5 + 5;
int n, f[N];
char s[N];
inline int getsg(int x) {
	if (x <= 200) return f[x];
	x -= 200;
	x %= 34;
	return f[200 - 34 + x];
}
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	freopen("lx.out", "w", stdout);
	#endif
	int mx = 0;
	for (int i = 2; i <= 200; ++i) {
		vector <int> vl;
		for (int j = 2; j <= i; ++j) vl.pb(f[j - 2] ^ f[i - j]);
		sort(vl.begin(), vl.end());
		vl.erase(unique(vl.begin(), vl.end()), vl.end());
		f[i] = 0;
		for (int j = 0; j < (int) vl.size(); ++j) {
			if (vl[j] != f[i]) break;
			++f[i];
		}
		mx = max(mx, f[i]);
		if (i > 100) { if (f[i] != f[i - 34]) {cerr << i; return 0;} }
	}
	for (int tt = read(); tt; --tt) {
		n = read();
		scanf("%s", s + 1);
		int ct1 = 0, ct2 = 0;
		for (int i = 1; i <= n; ++i) if (s[i] == 'R') ++ct1; else ++ct2;
		if (ct1 > ct2) {
			puts("Alice");
			continue;
		}
		if (ct1 < ct2) {
			puts("Bob");
			continue;
		}
		int res = 0;
		for (int l, r, i = 2; i <= n; ++i) {
			if (s[i] != s[i - 1]) {
				l = i - 1, r = i;
				while (r < n && s[r + 1] != s[r]) ++r;
				res ^= getsg(r - l + 1);
				i = r;
				continue;
			}
		}
		puts(res ? "Alice" : "Bob");
	}
	return 0;
}