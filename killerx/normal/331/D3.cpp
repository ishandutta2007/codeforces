#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define rep(i, n) for (int i = 0; i < n; ++ i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll linf = 1LL << 60;
const ld eps = 1e-9;
int read() {
	int x = 0, f = 1, c = getchar();
	for(;!isdigit(c); c = getchar()) if(c == '-') f ^= 1;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}
void write(int x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) putchar('-'), x = -x;
	int stk[10], tp = 0;
	for (; x; x /= 10) stk[tp ++] = x - x / 10 * 10;
	for (; tp; putchar(48 + stk[-- tp]));
}

const int N = 1 << 18;
int n, b, q;
ll T[N];

struct Arrow {
	int x1, y1;
	int x2, y2;
	int dx, dy;
} a[N + N];

int id[N + N];
pair <pii, ll> go[N + N];
pair <int, ll> Go[N + N][50];
map <pii, int> belong;
vector <pii> vec;
vector <int> has[N];

void GO(int x, int y, int dx, int dy, ll t) {
	write(min(1LL * b, max(0LL, x + dx * t)));
	putchar(' ');
	write(min(1LL * b, max(0LL, y + dy * t)));
	putchar('\n');
}

int main() {
	n = read(), b = read();
	for (int i = 0; i < n; ++ i) {
		a[i].x1 = read(), a[i].y1 = read();
		a[i].x2 = read(), a[i].y2 = read();
		if (a[i].x1 == a[i].x2) a[i].dy = a[i].y1 < a[i].y2 ? 1 : -1;
		else a[i].dx = a[i].x1 < a[i].x2 ? 1 : -1;
	}
	q = read();
	for (int i = 0; i < q; ++ i) {
		a[i + n].x1 = read(), a[i + n].y1 = read();
		a[i + n].x2 = a[i + n].x1, a[i + n].y2 = a[i + n].y1;
		char c = getchar();
		if (c == 'D') a[i + n].dy = -1; if (c == 'U') a[i + n].dy = 1;
		if (c == 'L') a[i + n].dx = -1; if (c == 'R') a[i + n].dx = 1;
		scanf("%lld", &T[i]);
	}

	set <pii> st;
	set <pii> :: iterator it, l, r;
	for (int i = 0; i < n + q; ++ i) go[i] = MP(MP(inf, inf), linf);

	for (int i = 0; i < n + q; ++ i) id[i] = i;
	st.clear();
	sort(id, id + n + q, [&] (int x, int y) {
		if (min(a[x].x1, a[x].x2) != min(a[y].x1, a[y].x2))
			return min(a[x].x1, a[x].x2) > min(a[y].x1, a[y].x2);
		return x > y;
	});
	for (int ii = 0; ii < n + q; ++ ii) {
		int i = id[ii];
		if (i < n) {
			l = st.lower_bound(MP(min(a[i].y1, a[i].y2), 0));
			r = st.lower_bound(MP(max(a[i].y1, a[i].y2) + 1, 0));
			for (it = l; it != r; it = st.erase(it)) {
				belong[MP(min(a[it -> S].x2, max(a[i].x1, a[i].x2)), it -> F)] = i;
				go[it -> S] = MP(MP(min(a[it -> S].x2, max(a[i].x1, a[i].x2)), it -> F), max(0, a[it -> S].x2 - max(a[i].x1, a[i].x2)));
			}
		}
		if (a[i].dx == -1) {
			st.insert(MP(a[i].y2, i));
		}
	}
	st.clear();
	sort(id, id + n + q, [&] (int x, int y) {
		if (max(a[x].x1, a[x].x2) != max(a[y].x1, a[y].x2))
			return max(a[x].x1, a[x].x2) < max(a[y].x1, a[y].x2);
		return x > y;
	});
	for (int ii = 0; ii < n + q; ++ ii) {
		int i = id[ii];
		if (i < n) {
			l = st.lower_bound(MP(min(a[i].y1, a[i].y2), 0));
			r = st.lower_bound(MP(max(a[i].y1, a[i].y2) + 1, 0));
			for (it = l; it != r; it = st.erase(it)) {
				belong[MP(max(a[it -> S].x2, min(a[i].x1, a[i].x2)), it -> F)] = i;
				go[it -> S] = MP(MP(max(a[it -> S].x2, min(a[i].x1, a[i].x2)), it -> F), max(0, min(a[i].x1, a[i].x2) - a[it -> S].x2));
			}
		}
		if (a[i].dx == 1) {
			st.insert(MP(a[i].y2, i));
		}
	}
	st.clear();
	sort(id, id + n + q, [&] (int x, int y) {
		if (min(a[x].y1, a[x].y2) != min(a[y].y1, a[y].y2))
			return min(a[x].y1, a[x].y2) > min(a[y].y1, a[y].y2);
		return x > y;
	});
	for (int ii = 0; ii < n + q; ++ ii) {
		int i = id[ii];
		if (i < n) {
			l = st.lower_bound(MP(min(a[i].x1, a[i].x2), 0));
			r = st.lower_bound(MP(max(a[i].x1, a[i].x2) + 1, 0));
			for (it = l; it != r; it = st.erase(it)) {
				belong[MP(it -> F, min(a[it -> S].y2, max(a[i].y1, a[i].y2)))] = i;
				go[it -> S] = MP(MP(it -> F, min(a[it -> S].y2, max(a[i].y1, a[i].y2))), max(0, a[it -> S].y2 - max(a[i].y1, a[i].y2)));
			}
		}
		if (a[i].dy == -1) {
			st.insert(MP(a[i].x2, i));
		}
	}
	st.clear();
	sort(id, id + n + q, [&] (int x, int y) {
		if (max(a[x].y1, a[x].y2) != max(a[y].y1, a[y].y2))
			return max(a[x].y1, a[x].y2) < max(a[y].y1, a[y].y2);
		return x > y;
	});
	for (int ii = 0; ii < n + q; ++ ii) {
		int i = id[ii];
		if (i < n) {
			l = st.lower_bound(MP(min(a[i].x1, a[i].x2), 0));
			r = st.lower_bound(MP(max(a[i].x1, a[i].x2) + 1, 0));
			for (it = l; it != r; it = st.erase(it)) {
				belong[MP(it -> F, max(a[it -> S].y2, min(a[i].y1, a[i].y2)))] = i;
				go[it -> S] = MP(MP(it -> F, max(a[it -> S].y2, min(a[i].y1, a[i].y2))), max(0, min(a[i].y1, a[i].y2) - a[it -> S].y2));
			}
		}
		if (a[i].dy == 1) {
			st.insert(MP(a[i].x2, i));
		}
	}
	for (int i = 0; i < n; ++ i) belong[MP(a[i].x2, a[i].y2)] = i;
	for (auto x : belong) {
		vec.PB(x.F);
		has[x.S].PB(vec.size() - 1);
	}
	for (int i = 0; i < vec.size(); ++ i) Go[i][0] = MP(i, 0LL);
	for (int i = 0; i < n; ++ i) {
		sort(has[i].begin(), has[i].end(), [&] (int x, int y) {
			return  vec[x].F == vec[y].F ?
					(vec[x].S - vec[y].S) * a[i].dy < 0 :
					(vec[x].F - vec[y].F) * a[i].dx < 0;
		});
		for (int j = 0; j + 1 < has[i].size(); ++ j) {
			Go[has[i][j]][0] = MP(has[i][j + 1], abs(vec[has[i][j + 1]].F - vec[has[i][j]].F + vec[has[i][j + 1]].S - vec[has[i][j]].S));
		}
		if (go[i] == MP(MP(inf, inf), linf)) continue;
		Go[has[i].back()][0] = MP(lower_bound(vec.begin(), vec.end(), go[i].F) - vec.begin(), go[i].S);
	}
	for (int j = 1; j < 50; ++ j) {
		for (int i = 0; i < vec.size(); ++ i) {
			pair <int, ll> p, np;
			p = Go[i][j - 1];
			np = Go[p.F][j - 1];
			Go[i][j] = MP(np.F, min(p.S + np.S, linf));
		}
	}
	// for (int i = 0; i < n + q; ++ i) cerr << "Arrow " << i << " to (" << go[i].F.F << "," << go[i].F.S << ") cost " << go[i].S << endl;
	// for (int i = 0; i < vec.size(); ++ i) cerr << i << " to " << Go[i][0].F << " cost " << Go[i][0].S << endl;
	// for (int i = 0; i < vec.size(); ++ i) cerr << i << ": " << vec[i].F << " " << vec[i].S << endl;
	for (int i = 0; i < q; ++ i) {
		// cerr << "query " << i << endl;
		ll t = T[i];
		pair <pii, ll> fst = go[i + n];
		if (fst == MP(MP(inf, inf), linf) || t < fst.S) {
			GO(a[i + n].x1, a[i + n].y1, a[i + n].dx, a[i + n].dy, t);
		} else {
			int nw = lower_bound(vec.begin(), vec.end(), fst.F) - vec.begin();
			t -= fst.S;
			// cerr << nw << " " << t << endl;
			for (int j = 50 - 1; ~j; -- j) {
				pair <int, ll> p = Go[nw][j];
				if (t < p.S) continue;
				nw = p.F, t -= p.S;
				// cerr << nw << " " << t << endl;
			}
			int id = belong[vec[nw]];
			GO(vec[nw].F, vec[nw].S, a[id].dx, a[id].dy, t);
		}
	}
	return 0;
}