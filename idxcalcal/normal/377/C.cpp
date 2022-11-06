#include <bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define ppp pop_back
#define rez resize
#define gc getchar
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef pair <int, ll> pil;
typedef vector <int> poly;
typedef vector <pii> vii;
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1; !isdigit(ch); f ^= ch == '-', ch = gc());
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
}
const int N = 105, M = 20;
const int inf = 0x3f3f3f3f;
int n, a[N], m, f[1 << M];
char s[N];
int typ[N], id[N], ct[1 << M];
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	n = read();
	for (ri i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	m = read();
	for (ri i = 1; i <= m; ++i) {
		scanf("%s", s);
		if (s[0] == 'p') typ[i] = 1;
		else typ[i] = 2;
		id[i] = read();
	}
	for (ri s = 1, j; s < (1 << m); ++s) {
		ct[s] = ct[s >> 1] + (s & 1);
		j = m - ct[s] + 1;
		f[s] = id[j] == 1 ? -inf : inf;
		for (ri i = 0, t = 1; i < m && s >= t; t <<= 1, ++i) if (s & t) {
			if (typ[j] == 1) {
				if (id[j] == 1) f[s] = max(f[s], f[s ^ t] + a[i + 1]);
				else f[s] = min(f[s], f[s ^ t] - a[i + 1]);
			} else {
				if (id[j] == 1) f[s] = max(f[s], f[s ^ t]);
				else f[s] = min(f[s], f[s ^ t]);
			}
		}
	}
	cout << f[(1 << m) - 1];
	return 0;
}