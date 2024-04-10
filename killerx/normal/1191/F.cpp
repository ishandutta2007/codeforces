#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n;
int x[200005], y[200005];
int vx[200005], cx;
int vy[200005], cy;
int lst[200005];
vi xy[200005], yx[200005];

int getx(int x) {return lower_bound(vx, vx + cx, x) - vx;}
int gety(int y) {return lower_bound(vy, vy + cy, y) - vy;}

struct mtree {
	vi node[800005];
	int siz;
	void ini() {
		for (siz = 1; siz <= cx; siz <<= 1) ;
		rep(i, cx) node[i + siz].pb(*max_element(xy[i].begin(), xy[i].end()));
		for (int i = siz - 1; i; -- i) {
			node[i].resize(node[i + i].size() + node[i + i + 1].size());
			merge(node[i + i].begin(), node[i + i].end(), node[i + i + 1].begin(), node[i + i + 1].end(), node[i].begin());
		}
	}
	int qry(int l, int r, int x) {
		int cnt = 0;
		for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) cnt += node[l].end() - lower_bound(node[l].begin(), node[l].end(), x), ++ l;
			if (r & 1) -- r, cnt += node[r].end() - lower_bound(node[r].begin(), node[r].end(), x);
		}
		return cnt;
	}
} segt;

int main() {
	n = read();
	rep(i, n) x[i] = read(), y[i] = read();
	rep(i, n) vx[cx ++] = x[i];
	rep(i, n) vy[cy ++] = y[i];
	sort(vx, vx + cx); sort(vy, vy + cy);
	cx = unique(vx, vx + cx) - vx;
	cy = unique(vy, vy + cy) - vy;
	rep(i, n) xy[getx(x[i])].pb(gety(y[i]));
	rep(i, n) yx[gety(y[i])].pb(getx(x[i]));
	ll ans = 0;
	segt.ini();
	rep(i, cy) {
		sort(yx[i].begin(), yx[i].end());
		rep(j, yx[i].size()) {
			int L = segt.qry(j ? yx[i][j - 1] + 1 : 0, yx[i][j] + 1, i);
			int R = segt.qry(yx[i][j], cx, i);
			ans += 1LL * L * R;
		}
	}
	printf("%lld\n", ans);
	return 0;
}