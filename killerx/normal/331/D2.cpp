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

const int N = 1 << 17;

const char * Dir = "UDLR";
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

struct SegT {
	pii mn[N << 1];

	void init() {
		for (int i = 0; i < (N << 1); ++ i)
			mn[i] = MP(inf, 0);
	}
	void chkmin(pii &x, pii y) {if (y < x) x = y;}

	void upd(int l, int r, pii v) {
		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) chkmin(mn[l ++], v);
			if (r & 1) chkmin(mn[-- r], v);
		}
	}

	pii qry(int x) {
		pii ans = MP(inf, 0);
		for (x += N; x; x >>= 1) {
			chkmin(ans, mn[x]);
		}
		return ans;
	}
} segt;

int n, b, q;

vector <pair <pii, pii> > arrow;
vector <pair <pii, pair <int, ll> > > qry;

struct Arrow {
	int x1, y1;
	int x2, y2;
	int dir, id;

	int getLowCol() {return min(y1, y2);}
	int getHighCol() {return max(y1, y2);}
	int getLowRow() {return min(x1, x2);}
	int getHighRow() {return max(x1, x2);}
} a[N + N];

bool cmp1(Arrow a, Arrow b) {return a.getHighCol() > b.getHighCol() || (a.getHighCol() == b.getHighCol() && a.id < b.id);}
bool cmp2(Arrow a, Arrow b) {return a.getLowCol() < b.getLowCol() || (a.getLowCol() == b.getLowCol() && a.id < b.id);}
bool cmp3(Arrow a, Arrow b) {return a.getHighRow() > b.getHighRow() || (a.getHighRow() == b.getHighRow() && a.id < b.id);}
bool cmp4(Arrow a, Arrow b) {return a.getLowRow() < b.getLowRow() || (a.getLowRow() == b.getLowRow() && a.id < b.id);}

map <pii, pair <pii, ll> > go;
int dir[N]; map <pii, int> belong;
vector <pii> vec;
vector <pair <int, ll> > Go[50];
vector <int> has[N];
pair <pii, ll> fstGo[N];

void print(int a, int b) {
	write(a);
	putchar(' ');
	write(b);
	putchar('\n');
}

void mov(int x, int y, int tp, ll t) {
	if (tp < 2) {
		if (tp == 0) {
			if (y + t >= b) print(x, b);
			else print(x, y + t);
		} else {
			if (y - t <= 0) print(x, 0);
			else print(x, y - t);
		}
	} else {
		if (tp == 2) {
			if (x - t <= 0) print(0, y);
			else print(x - t, y);
		} else {
			if (x + t >= b) print(b, y);
			else print(x + t, y);
		}
	}
}

int main() {
	n = read(), b = read();
	for (int i = 0; i < n; ++ i) {
		int x1 = read(), y1 = read();
		int x2 = read(), y2 = read();
		arrow.PB(MP(MP(x1, y1), MP(x2, y2)));
	}
	q = read();
	for (int i = 0; i < q; ++ i) {
		int x = read(), y = read();
		char c = getchar();
		int dir = strchr(Dir, c) - Dir;
		ll t; scanf("%lld", &t);
		qry.PB(MP(MP(x, y), MP(dir, t)));
	}

	for (int i = 0; i < n; ++ i) {
		int x1, x2, y1, y2, tp;
		x1 = arrow[i].F.F, y1 = arrow[i].F.S;
		x2 = arrow[i].S.F, y2 = arrow[i].S.S;
		tp = (x1 == x2 ? y1 < y2 ? 0 : 1 : x1 < x2 ? 3 : 2);
		dir[i] = tp;
		a[i] = (Arrow) {x1, y1, x2, y2, tp, i};
	}
	for (int i = 0; i < q; ++ i) {
		int x, y, dir;
		x = qry[i].F.F, y = qry[i].F.S;
		dir = qry[i].S.F;
		a[i + n] = (Arrow) {x, y, x, y, dir, i + n};
		fstGo[i] = MP(MP(inf, inf), linf);
	}
	sort(a, a + n + q, cmp1);
	segt.init();
	for (int i = 0; i < n + q; ++ i) {
		// cerr << a[i].id << " ";
		if (a[i].dir == 0) {
			pii p = segt.qry(a[i].x2);
			if (p.F != inf) {
				pair <pii, ll> np = MP(MP(a[i].x2, max(a[i].y2, p.F)), max(0, p.F - a[i].y2));
				if (a[i].id < n) {
					go[MP(a[i].x2, a[i].y2)] = np;
					belong[MP(a[i].x2, a[i].y2)] = a[i].id;
				} else {
					fstGo[a[i].id - n] = np;
				}
				belong[MP(a[i].x2, max(a[i].y2, p.F))] = p.S;
			}
		}
		if (a[i].id < n) segt.upd(min(a[i].x1, a[i].x2), max(a[i].x1, a[i].x2) + 1, MP(a[i].getLowCol(), a[i].id));
	}
	// cerr << endl;
	sort(a, a + n + q, cmp2);
	segt.init();
	for (int i = 0; i < n + q; ++ i) {
		// cerr << a[i].id << " ";
		if (a[i].dir == 1) {
			pii p = segt.qry(a[i].x2);
			if (p.F != inf) {
				pair <pii, ll> np = MP(MP(a[i].x2, min(a[i].y2, -p.F)), max(0, a[i].y2 + p.F));
				if (a[i].id < n) {
					go[MP(a[i].x2, a[i].y2)] = np;
					belong[MP(a[i].x2, a[i].y2)] = a[i].id;
				} else {
					fstGo[a[i].id - n] = np;
				}
				belong[MP(a[i].x2, min(a[i].y2, -p.F))] = p.S;
			}
		}
		if (a[i].id < n) segt.upd(min(a[i].x1, a[i].x2), max(a[i].x1, a[i].x2) + 1, MP(-a[i].getHighCol(), a[i].id));
	}
	// cerr << endl;
	sort(a, a + n + q, cmp3);
	segt.init();
	for (int i = 0; i < n + q; ++ i) {
		// cerr << a[i].id << " ";
		if (a[i].dir == 3) {
			pii p = segt.qry(a[i].y2);
			if (p.F != inf) {
				pair <pii, ll> np = MP(MP(max(a[i].x2, p.F), a[i].y2), max(0, p.F - a[i].x2));
				if (a[i].id < n) {
					go[MP(a[i].x2, a[i].y2)] = np;
					belong[MP(a[i].x2, a[i].y2)] = a[i].id;
				} else {
					fstGo[a[i].id - n] = np;
				}
				belong[MP(max(a[i].x2, p.F), a[i].y2)] = p.S;
			}
		}
		if (a[i].id < n) segt.upd(min(a[i].y1, a[i].y2), max(a[i].y1, a[i].y2) + 1, MP(a[i].getLowRow(), a[i].id));
	}
	// cerr << endl;
	sort(a, a + n + q, cmp4);
	segt.init();
	for (int i = 0; i < n + q; ++ i) {
		// cerr << a[i].id << " ";
		if (a[i].dir == 2) {
			pii p = segt.qry(a[i].y2);
			if (p.F != inf) {
				pair <pii, ll> np = MP(MP(min(a[i].x2, -p.F), a[i].y2), max(0, a[i].x2 + p.F));
				if (a[i].id < n) {
					go[MP(a[i].x2, a[i].y2)] = np;
					belong[MP(a[i].x2, a[i].y2)] = a[i].id;
				} else {
					fstGo[a[i].id - n] = np;
				}
				belong[MP(min(a[i].x2, -p.F), a[i].y2)] = p.S;
			}
		}
		if (a[i].id < n) segt.upd(min(a[i].y1, a[i].y2), max(a[i].y1, a[i].y2) + 1, MP(-a[i].getHighRow(), a[i].id));
	}
	// cerr << endl;
	for (int i = 0; i < n; ++ i) belong[arrow[i].S] = i;
	// for (auto p : go) cerr << p.F.F << " " << p.F.S << " -> " << p.S.F.F << " " << p.S.F.S << " cost " << p.S.S << endl;
	for (auto p : belong) vec.PB(p.F);
	// for (auto p : belong) cerr << p.F.F << "," << p.F.S << " " << p.S << endl;
	for (int i = 0; i < vec.size(); ++ i) has[belong[vec[i]]].PB(i);
	// for (int i = 0; i < vec.size(); ++ i) cerr << i << ": " << "(" << vec[i].F << ", " << vec[i].S << ")" << endl;
	for (int i = 0; i < 50; ++ i) Go[i].resize(vec.size());
	for (int i = 0; i < vec.size(); ++ i) Go[0][i] = MP(i, 0);
	for (int i = 0; i < n; ++ i) {
		int x1 = arrow[i].F.F, y1 = arrow[i].F.S;
		int x2 = arrow[i].S.F, y2 = arrow[i].S.S;
		int tp = (x1 == x2 ? y1 < y2 ? 0 : 1 : x1 < x2 ? 3 : 2);
		sort(has[i].begin(), has[i].end(), [&] (int a, int b) {
			return (vec[a].F - vec[b].F + vec[a].S - vec[b].S) / (dx[tp] + dy[tp]) < 0;
		});
		// cerr << i << ": "; for (int j = 0; j < has[i].size(); ++ j) cerr << has[i][j] << " "; cerr << endl;
		for (int j = 0; j + 1 < has[i].size(); ++ j) {
			Go[0][has[i][j]] = MP(has[i][j + 1], abs(vec[has[i][j]].F - vec[has[i][j + 1]].F + vec[has[i][j]].S - vec[has[i][j + 1]].S));
		}
		if (!go.count(vec[has[i].back()])) continue;
		pair <pii, ll> p = go[vec[has[i].back()]];
		// cerr << has[i].back() << " " << p.F.F << ", " << p.F.S << endl;
		Go[0][has[i].back()] = MP(lower_bound(vec.begin(), vec.end(), p.F) - vec.begin(), p.S);
	}
	for (int j = 1; j < 50; ++ j) {
		for (int i = 0; i < vec.size(); ++ i) {
			pair <int, ll> p = Go[j - 1][i];
			pair <int, ll> np = Go[j - 1][p.F];
			Go[j][i] = MP(np.F, np.S + p.S);
			if (Go[j][i].S > linf) Go[j][i].S = linf;
		}
	}
	// for (int j = 0; j < 10; ++ j) {
	// 	cerr << j << ": " << endl;
	// 	for (int i = 0; i < vec.size(); ++ i) cerr << i << " -> " << Go[j][i].F << " " << Go[j][i].S << endl;
	// }
	for (int i = 0; i < q; ++ i) {
		// cerr << "Query " << i << endl;
		pair <pii, ll> p = fstGo[i];
		int x = qry[i].F.F, y = qry[i].F.S;
		int tp = qry[i].S.F;
		ll t = qry[i].S.S;
		// cerr << p.F.F << "," << p.F.S << " " << p.S << endl;
		if (p.F.F == inf || t < p.S) {
			mov(x, y, tp, t);
		} else {
			int nw = lower_bound(vec.begin(), vec.end(), p.F) - vec.begin();
			t -= p.S;
			// cerr << nw << " " << t << endl;
			for (int j = 50 - 1; ~j; -- j) {
				pair <int, ll> P = Go[j][nw];
				if (P.S <= t) {
					t -= P.S;
					nw = P.F;
					// cerr << nw << " " << t << endl;
				}
			}
			mov(vec[nw].F, vec[nw].S, dir[belong[vec[nw]]], t);
		}
	}
	return 0;
}