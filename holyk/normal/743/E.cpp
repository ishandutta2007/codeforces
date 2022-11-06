#include <bits/stdc++.h>
#define REP(i, a, b) for (int i(a); i <= (b); ++i)

#define gc getchar()
struct Reader {
	template <class T> inline operator T() {
		char c, p = 0; T w;
		while (!isdigit(c = gc)) if (c == '-') p = 1;
		for (w = c & 15; isdigit(c = gc); w = w * 10 + (c & 15));
		return p ? -w : w;
	}
} rd;

template <class T> inline bool smin(T&x, const T&y) { return y < x ? x = y, 1 : 0; }
template <class T> inline bool smax(T&x, const T&y) { return x < y ? x = y, 1 : 0; }

typedef long long ll;

const int N(1005);
int n, m, a[N], ne[N][150], c[8];
void init() {
	n = rd, m = n;
	static int pos[8];
	REP(i, 1, n) {
		a[i] = (int)rd - 1;
		++c[a[i]];	
	}
	REP(i, 0, 7) smin(m, c[i]);
	for (int i = n; i; pos[a[i]] = i, --i) {
		ne[i][1] = i + 1;
		if (!pos[a[i]]) continue;
		for (int j = m + 1; j; --j)
			ne[i][j + 1] = ne[pos[a[i]]][j];
	}
//	REP(i, 1, n) REP(j, 0, m)
//		printf("%d%c", ne[i][j], " \n"[j == m]);
}
int f[N][280], ans;
bool check(int x) {
	static const int ST = (1 << 8) - 1;
	memset(f, -1, sizeof f);
	f[1][0] = 0;
	REP(i, 1, n) REP(s, 0, ST) if (~f[i][s]) {
		smax(f[i + 1][s], f[i][s]);
		if (s >> a[i] & 1) continue;
		if (ne[i][x])
			smax(f[ne[i][x]][s | 1 << a[i]], f[i][s] + x);
		if (ne[i][x + 1])
			smax(f[ne[i][x + 1]][s | 1 << a[i]], f[i][s] + x + 1);
		
	}
	if (~f[n + 1][ST]) return smax(ans, f[n + 1][ST]), 1;
	return 0;
}
int main() {
	init();
	REP(i, 0, 7) if (c[i]) ++ans;
	int l = 1, r = m;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	std::cout << ans;
	return 0;
}