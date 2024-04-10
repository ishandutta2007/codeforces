#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const ll INF = (ll)1e17;
const int N = 2020;
int n, m;
ll dpV[N][N][2][2];
ll dpE[N][N][2][2];
ll a[N][2];
pii ord[N];
int st[N];
int stSz;
int ed[N][2];
vector<int> g[N];
int sz[N];
int ans[N];
vector<int> lb, rb;
set<pii> segms;
int finSegm[N][2];

void dfsRestore(int v, int s, int fl, int fr);

void mergeSon(int v, int u, int id1, int id2) {
	for (int x = 0; x < sz[v]; x++)
		for (int y = 0; y < sz[u]; y++)
			for (int fl = 0; fl < 2; fl++)
				for (int fm = 0; fm < 2; fm++)
					for (int fr = 0; fr < 2; fr++) {
						ll w = dpE[id1][x][fl][fm] + dpV[u][y][fm][fr];
						if (w < -INF / 2) continue;
						dpE[id2][x + y + fm][fl][fr] = max(dpE[id2][x + y + fm][fl][fr], w);
					}
}

void unmergeSon(ll &curW, int &ss, int &ffl, int &ffr, int v, int u, int id1, int id2) {
	for (int x = 0; x < sz[v]; x++)
		for (int y = 0; y < sz[u]; y++)
			for (int fl = 0; fl < 2; fl++)
				for (int fm = 0; fm < 2; fm++)
					for (int fr = 0; fr < 2; fr++) {
						if (fl != ffl || fr != ffr) continue;
						ll w = dpE[id1][x][fl][fm] + dpV[u][y][fm][fr];
						if (w < -INF / 2) continue;
						if (w != curW) continue;
						if (x + y + fm != ss) continue;
						dfsRestore(u, y, fm, fr);
						curW = dpE[id1][x][fl][fm];
						ss = x;
						ffl = fl;
						ffr = fm;
						return;
					}
	assert(false);
}


void dfsDp(int v) {
	eprintf("dfsDp %d\n", v);
	sz[v] = 1;
	if (g[v].empty()) {
		for (int f = 0; f < 2; f++)
			for (int h = 0; h < 2; h++) {
				ll w = a[v][1] - a[v][0];
				if (f) w += a[v][0];
				if (h) w -= a[v][1];
				dpV[v][0][f][h] = w;
			}
		return;
	}
	for (int id : g[v]) dfsDp(ed[id][1]);
	int u = ed[g[v][0]][1];
	for (int s = 0; s < sz[u]; s++)
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++)
				dpE[g[v][0]][s][x][y] = dpV[u][s][x][y];
	sz[v] += sz[u];
	for (int it = 1; it < (int)g[v].size(); it++) {
		int id = g[v][it];
		u = ed[id][1];
		mergeSon(v, u, g[v][it - 1], id);
		sz[v] += sz[u];
	}
	for (int s = 0; s < sz[v]; s++)
		for (int fl = 0; fl < 2; fl++)
			for (int fr = 0; fr < 2; fr++) {
				ll w = dpE[g[v].back()][s][fl][fr];
				if (w < -INF / 2) continue;
				if (fl) {
					dpV[v][s][0][fr] = max(dpV[v][s][0][fr], w - a[v][0]);
					dpV[v][s][1][fr] = max(dpV[v][s][1][fr], w);
				}
				if (s > 0) {
					dpV[v][s - 1][fl][fr] = max(dpV[v][s - 1][fl][fr], w);
				}
				if (fr) {
					dpV[v][s][fl][0] = max(dpV[v][s][fl][0], w + a[v][1]);
					dpV[v][s][fl][1] = max(dpV[v][s][fl][1], w);
				}
			}
}

void addLeft(int x) {
	eprintf("addLeft %d\n", x);
	lb.push_back(x);
}
void addRight(int x) {
	eprintf("addRight %d\n", x);
	rb.push_back(x);
}

void dfsRestore(int v, int s, int fl, int fr) {
	eprintf("dfsRestore %d %d %d %d\n", v, s, fl, fr);
	if (g[v].empty()) {
		addLeft(a[v][0]);
		addRight(a[v][1]);
		ans[v] = 0;
		if (fl) addRight(a[v][0]);
		if (fr) addLeft(a[v][1]);
		return;
	}
	ll curW = dpV[v][s][fl][fr];
	bool fnd = false;
	for (int ns = 0; !fnd && ns < sz[v]; ns++)
		for (int nfl = 0; !fnd && nfl < 2; nfl++)
			for (int nfr = 0; !fnd && nfr < 2; nfr++) {
				ll w = dpE[g[v].back()][ns][nfl][nfr];
				if (w < -INF / 2) continue;
				if (nfl && nfr == fr && ns == s) {
					ll nw = w;
					if (fl == 0) nw -= a[v][0];
					if (nw == curW) {
						fnd = true;
						addLeft(a[v][0]);
						curW = w;
						if (fl) addRight(a[v][0]);
						fl = nfl;
						ans[v] = -1;
						break;
					}
				}
				if (ns > 0 && nfl == fl && nfr == fr && ns == s + 1) {
					if (curW == w) {
						fnd = true;
						s = ns;
						ans[v] = 0;
						break;
					}
				}
				if (nfr && nfl == fl && ns == s) {
					ll nw = w;
					if (fr == 0) nw += a[v][1];
					if (nw == curW) {
						fnd = true;
						addRight(a[v][1]);
						curW = w;
						if (fr) addLeft(a[v][1]);
						fr = nfr;
						ans[v] = 1;
						break;
					}
				}
			}
	assert(fnd);
	for (int it = (int)g[v].size() - 1; it > 0; it--) {
		int id = g[v][it];
		int u = ed[id][1];
		sz[v] -= sz[u];
		unmergeSon(curW, s, fl, fr, v, u, g[v][it - 1], id);
	}
	dfsRestore(ed[g[v][0]][1], s, fl, fr);
	eprintf("endRestore %d\n", v);
}

void dfsSegms(int v) {
	for (int id : g[v]) dfsSegms(ed[id][1]);
	if (ans[v] == -1) {
		auto it = segms.lower_bound(mp(a[v][0], -1));
		assert(it != segms.end());
		assert(it->first == a[v][0]);
		finSegm[v][0] = it->first;
		finSegm[v][1] = it->second;
		segms.erase(it);
	} else if (ans[v] == 0) {
		auto it = segms.lower_bound(mp(a[v][0], -1));
		assert(it != segms.end());
		assert(it->second <= a[v][1]);
		finSegm[v][0] = it->first;
		finSegm[v][1] = it->second;
		segms.erase(it);
	} else {
		auto it = segms.lower_bound(mp(a[v][1], -1));
		assert(it != segms.begin());
		it--;
		assert(it->second == a[v][1]);
		finSegm[v][0] = it->first;
		finSegm[v][1] = it->second;
		segms.erase(it);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i][0], &a[i][1]);
		ord[i] = mp((int)a[i][0], i);
	}
	sort(ord, ord + n);
	for (int i = n - 1; i >= 0; i--) {
		int v = ord[i].second;
		while(stSz > 0 && a[v][1] > a[st[stSz - 1]][0]) {
			stSz--;
			g[v].push_back(m);
			ed[m][0] = v;
			ed[m][1] = st[stSz];
			eprintf("edge %d %d\n", v, st[stSz]);
			m++;
		}
		st[stSz++] = v;
	}
	for (int v = 0; v < n; v++)
		for (int s = 0; s <= n; s++)
			for (int x = 0; x < 2; x++)
				for (int y = 0; y < 2; y++)
					dpV[v][s][x][y] = dpE[v][s][x][y] = -INF;
	for (int i = 0; i < stSz; i++)
		dfsDp(st[i]);
	ll ansVal = 0;
	for (int i = 0; i < stSz; i++) {
		int v = st[i];
		ansVal += dpV[v][0][0][0];
	}
	printf("%lld\n", ansVal);
	for (int i = 0; i < stSz; i++) {
		int v = st[i];
		dfsRestore(v, 0, 0, 0);
	}
	assert((int)lb.size() == n);
	assert((int)rb.size() == n);
	sort(all(lb));
	sort(all(rb));
	for (int i = 0; i < n; i++)
		segms.insert(mp(lb[i], rb[i]));
	for (int i = 0; i < stSz; i++) {
		int v = st[i];
		dfsSegms(v);
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", finSegm[i][0], finSegm[i][1]);

	return 0;
}