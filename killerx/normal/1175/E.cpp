#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define eps 1e-10
#define inf 0x3f3f3f3f
#define mod 1000000007
#define linf 1LL << 60

#define ll long long
#define ld long double
#define vi vector <int>
#define vpii vector <pii>
#define pii pair <int, int>

#define os ostream
template <typename T1, typename T2>
os & operator << (os & out, pair <T1, T2> x) {
	return out << "(" << x.first << "," << x.second << ")";
}
#define dbg(x) cerr << #x << " = " << x << endl
#define rep(i,n) for (int i = 0, Ed = (int) (n); i < Ed; ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)
#define fio(fn) freopen(fn".in", "r", stdin), freopen(fn".out", "w", stdout)
#define fastio() ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

template <typename T = int>
inline T read() {
	T x = 0; int f = 1, c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == 45) f ^= 1;
	for (;  isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

template <typename T>
inline void write(T x) {
	int stk[20], tp = 0;
	if (x < 0) putchar(45), x = -x;
	if (!x) putchar(48);
	for (; x; stk[tp ++] = x % 10, x /= 10);
	for (; tp; putchar(48 + stk[-- tp]));
}

#define N (1 << 20)

void chk(int & x, int y) {
	if (y > x) x = y;
}

struct SegT {
	int mn[N + N];
	void init() {
		rep(i, N + N) mn[i] = -1;
	}
	void upd(int l, int r, int v) {
		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) chk(mn[l ++], v);
			if (r & 1) chk(mn[-- r], v);
		}
	}
	int qry(int x) {
		int ans = -1;
		for (x += N; x; x >>= 1) {
			chk(ans, mn[x]);
		}
		return ans;
	}
};
SegT segt;

int go[N][20];
int main() {
	int n = read(), q = read();
	segt.init();
	rep(i, n) {
		int l = read(), r = read();
		segt.upd(l, r, r);
	}
	rep(i, N) {
		go[i][0] = segt.qry(i);
	}
	rep(j, 20) if (j) {
		rep(i, N) {
			if (!~go[i][j - 1]) go[i][j] = -1;
			else go[i][j] = go[go[i][j - 1]][j - 1];
		}
	}
	while (q --) {
		int x = read(), y = read();
		int ans = 0;
		for (int j = 19; ~j; -- j) {
			if (~go[x][j] && go[x][j] < y) {
				ans += 1 << j;
				x = go[x][j];
			}
		}
		if (!~go[x][0]) write(-1);
		else write(ans + 1);
		putchar(10);
	}
	return 0;
}