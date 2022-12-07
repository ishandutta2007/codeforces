#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long long ll;

using namespace std;

const int N = 211111;
int n, m;
int cost[N];
bool dead[N];

struct Tp {
	int l, r;
} a[N], b[N];

struct Te {
	int x, t, tag;
	bool operator<(const Te& B) const {
		return x < B.x || (x == B.x && t < B.t);
	}
} ev1[4*N];
int en1;

ll ans = 0;
int ansc = 0, ansr = 0;

ll inter(int l1, int r1, int l2, int r2) {
	int ll = max(l1, l2);
	int rr = min(r1, r2);
	if (ll > rr) return 0;
	return rr - ll;
}

void update(int chan, int rolik) {
	ll res = inter(b[chan].l, b[chan].r, a[rolik].l, a[rolik].r) * cost[chan];
	if (res > ans) {
		ans = res;
		ansc = chan;
		ansr = rolik;
	}
}

int h[4*N], hn = 0;
int encode(int x) {
	return lower_bound(h, h + hn, x) - h;
}

int maxvalue[N*16], maxtag[N*16];

void addmax(int x, int l, int value, int tag, int L, int R) {
	if (l > R || l < L) return;
	if (value > maxvalue[x]) {
		maxvalue[x] = value;
		maxtag[x] = tag;
	}
	if (l == L && l == R) {
		return;
	}
	addmax(x + x, l, value, tag, L, (R + L) >> 1);
	addmax(x + x + 1, l, value, tag, (R + L + 2) >> 1, R);		
}

pair<int, int> getmax(int x, int l, int r, int L, int R) {
	if (l > R || r < L) return {-1, -1};
	if (l <= L && r >= R) {
		return {maxvalue[x], maxtag[x]};
	}
	pair<int, int> t1 = getmax(x + x, l, r, L, (R + L) >> 1);
	pair<int, int> t2 = getmax(x + x + 1, l, r, (R + L + 2) >> 1, R);
	if (t1.first > t2.first)
		return t1;
	return t2;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    memset(maxvalue, -1, sizeof(maxvalue));
    memset(maxtag, -1, sizeof(maxtag));
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].l, &a[i].r);
		h[hn++] = a[i].l;
		h[hn++] = a[i].r;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &b[i].l, &b[i].r, &cost[i]);
		h[hn++] = b[i].l;
		h[hn++] = b[i].r;
	}
	sort(h, h + hn);
	hn = unique(h, h + hn) - h;

	{
		en1 = 0;
		for (int i = 0; i < n; ++i) {
			ev1[en1].x = a[i].l;
			ev1[en1].t = -1;
			ev1[en1].tag = i;
			++en1;
			ev1[en1].x = a[i].r;
			ev1[en1].t = +1;
			ev1[en1].tag = i;
			++en1;
		}
		for (int i = 0; i < m; ++i) {
			ev1[en1].x = b[i].l;
			ev1[en1].t = 0;
			ev1[en1].tag = i;
			++en1;

			ev1[en1].x = b[i].r;
			ev1[en1].t = 2;
			ev1[en1].tag = i;
			++en1;

		}
		sort(ev1, ev1 + en1);
		memset(dead, 0, sizeof(dead[0]) * (n + 2));
		priority_queue<pair<int, int> > q;
		for (int i = 0; i < en1; ++i) {
			if (ev1[i].t == -1) {
				q.push({ a[ev1[i].tag].r, ev1[i].tag });
			} else
			if (ev1[i].t == +1) {
				addmax( 1, encode(a[ev1[i].tag].l), a[ev1[i].tag].r - a[ev1[i].tag].l, ev1[i].tag, 0, hn - 1);

				dead[ ev1[i].tag ] = 1;
				while (q.size() && dead[q.top().second]) q.pop();
			} else 
			if (ev1[i].t == 0) {
				if (q.size())
				    update(ev1[i].tag, q.top().second);
			} else {
				int tt = ev1[i].tag;
				int cc = getmax( 1, encode(b[tt].l), encode(b[tt].r), 0, hn - 1).second;
				if (cc != -1) {
					update(tt, cc);
				}
			}
		}
	}
	{
		en1 = 0;
		for (int i = 0; i < n; ++i) {
			ev1[en1].x = a[i].l;
			ev1[en1].t = -1;
			ev1[en1].tag = i;
			++en1;
			ev1[en1].x = a[i].r;
			ev1[en1].t = +1;
			ev1[en1].tag = i;
			++en1;
		}
		for (int i = 0; i < m; ++i) {
			ev1[en1].x = b[i].r;
			ev1[en1].t = 0;
			ev1[en1].tag = i;
			++en1;
		}
		sort(ev1, ev1 + en1);
		reverse(ev1, ev1 + en1);

		memset(dead, 0, sizeof(dead[0]) * (n + 2));
		priority_queue<pair<int, int> > q;
		for (int i = 0; i < en1; ++i) {
			if (ev1[i].t == +1) {
				q.push({ -a[ev1[i].tag].l, ev1[i].tag });
			} else
			if (ev1[i].t == -1) {
				dead[ ev1[i].tag ] = 1;
				while (q.size() && dead[q.top().second]) q.pop();
			} else {
				if (q.size())
				    update(ev1[i].tag, q.top().second);
			}
		}
	}

	cout << ans << endl;
	if (ans) {
		cout << ansr + 1 << " " << ansc + 1 << endl;
	}
    
    return 0;
}