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
const int N = 1e5 + 5;
int n, m, S, rk[N], suf[N], Suf[N];
pii b[N];
pii chs[N];
set <pii> q;
struct abc {
	int a, b, c;
	abc(int _a = 0, int _b = 0, int _c = 0) {
		a = _a;
		b = _b;
		c = _c;
	}
} a[N];
inline bool operator < (abc a, abc b) {
	return a.a == b.a ? (a.b == b.b ? a.c < b.c : a.b < b.b) : a.a < b.a;
}
const int inf = 0x3f3f3f3f;
int id[N];
inline bool chk(int w) {
	int ss = 0, all = 0;
	int i = n;
	priority_queue <pii> q;
	for (ri j = m; j; --j) {
		while (i && rk[i] >= j) q.push(pii(-a[i].b, i)), --i;
		if (!ss) {
			if (!q.size()) return 0;
			int t = q.top().se;
			q.pop();
			ss += w - 1;
			all += a[t].b;
			if (all > S) return 0;
		} else --ss;
	}
	return 1;
}
int ct[N];
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	n = read();
	m = read();
	S = read();
	for (ri i = 1; i <= m; ++i) b[i] = pii(read(), i), chs[i] = pii(inf, 0);
	for (ri i = 1; i <= n; ++i) a[i].a = read();
	for (ri i = 1; i <= n; ++i) a[i].b = read();
	for (ri i = 1; i <= n; ++i) a[i].c = i;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	for (ri i = 1, j = 0; i <= n; ++i) {
		while (j < m && a[i].a >= b[j + 1].fi) ++j;
		rk[i] = j;
	}
	bool ff = 0;
	for (ri i = 1; i <= n; ++i) if (a[i].a >= b[m].fi) {
		if (a[i].b <= S) {
			ff = 1;
			break;
		}
	}
	if (!ff) return puts("NO"), 0;
	int ans = 0x3f3f3f3f, l = 1, r = m;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (chk(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	puts("YES");
	int w = ans;
	int ss = 0, all = 0;
	int i = n;
	priority_queue <pii> q;
	queue <int> qq;
	for (ri j = m; j; --j) {
		while (i && rk[i] >= j) q.push(pii(-a[i].b, i)), --i;
		if (!ss) {
			int t = q.top().se;
			q.pop();
			ss += (ct[t] = w);
			all += a[t].b;
			qq.push(t);
		}
		int t = qq.front();
		--ct[t];
		--ss;
		id[b[j].se] = a[t].c;
		if (!ct[t]) qq.pop();
	}
	for (ri i = 1; i <= m; ++i) cout << id[i] << ' ';
}