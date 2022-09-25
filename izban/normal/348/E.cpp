#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
bool f[maxn];
vector<pair<int, int> > e[maxn];
pair<int, int> d[maxn];
int p[maxn], L[maxn], R[maxn];
vector<pair<int, int> > a;


void dfs1(int v, int pr = -1, int h = 0) {
	L[v] = R[v] = a.size();
	a.push_back(make_pair(h, v));	
	int dist = -1, cnt = 0;
	if (f[v]) dist = 0, cnt = 1, p[v] = v;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i].first != pr) {
		dfs1(e[v][i].first, v, h + 1);
		if (dist < d[e[v][i].first].first + e[v][i].second && d[e[v][i].first].first != -1) {
			dist = d[e[v][i].first].first + e[v][i].second;
			cnt = 0;
			p[v] = p[e[v][i].first];
		}
		if (dist == d[e[v][i].first].first) {
			if (cnt) p[v] = v;
			cnt += d[e[v][i].first].second;
		}
		R[v] = a.size();
		a.push_back(make_pair(h, v));
	}
	d[v] = make_pair(dist, cnt);
}

vector<pair<int, int> > vct;

void dfs2(int v, int uDist, int uP, int pr = -1) {
	if (f[v]) {
		if (uDist > 0 && uDist > d[v].first) vct.push_back(make_pair(v, uP));
		if (d[v].first > 0 && d[v].first > uDist) vct.push_back(make_pair(v, p[v]));
	}
	if (uDist == -1 && f[v]) {
		uDist = 0;
		uP = v;
	}
	if (v == 1) e[v].push_back(make_pair(-1, 0));
	vector<pair<int, int> > mxL(e[v].size()), mxR(e[v].size());
	
	for (int i = 0; i < e[v].size(); i++) {
		pair<int, int> oldmx = i ? mxL[i - 1] : make_pair(-1, 0);
		pair<int, int> newmx = e[v][i].first == pr ? make_pair(uDist, uP) : make_pair(d[e[v][i].first].first, p[e[v][i].first]);
		if (newmx.first > -1 && e[v][i].first != pr) newmx.first += e[v][i].second;
		pair<int, int> cur = oldmx;
		if (newmx.first > cur.first) {
			cur = newmx;
		} else if (newmx.first == cur.first) {
			cur.second = v;
		}
		mxL[i] = cur;
	}

	for (int i = e[v].size() - 1; i >= 0; i--) {
		pair<int, int> oldmx = i < e[v].size() - 1 ? mxR[i + 1] : make_pair(-1, 0);
		pair<int, int> newmx = e[v][i].first == pr ? make_pair(uDist, uP) : make_pair(d[e[v][i].first].first, p[e[v][i].first]);
		if (newmx.first > -1 && e[v][i].first != pr) newmx.first += e[v][i].second;
		pair<int, int> cur = oldmx;
		if (newmx.first > cur.first) {
			cur = newmx;
		} else if (newmx.first == cur.first) {
			cur.second = v;
		}
		mxR[i] = cur;
	}

	for (int i = 0; i < e[v].size(); i++) if (e[v][i].first != pr) {
		pair<int, int> l = i ? mxL[i - 1] : make_pair(-1, 0);
		pair<int, int> r = i < e[v].size() - 1 ? mxR[i + 1] : make_pair(-1, 0);
		int D = l.first, P = l.second;
		if (r.first > D) {
			D = r.first, P = r.second;
		} else if (r.first == D) {
			P = v;
		}
		if (D > -1) D += e[v][i].second;
		dfs2(e[v][i].first, D, P, v);
	}
}

int pw[2 * maxn];
pair<int, int> mn[18][1 << 18];


void build() {
	int curi = 1, curpw = 0;
	while (curi < 1 << 18) {
		if (curi == (1 << (curpw + 1))) curpw++;
		pw[curi++] = curpw;
	}

	for (int i = 0; i < a.size(); i++) mn[0][i] = a[i];
	for (int j = 1; j < 18; j++) {
		for (int i = 0; i + (1 << j) <= a.size(); i++) {
			mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
		}
	}
}

int getmin(int l, int r) {
	int p = pw[r - l + 1];
	return min(mn[p][l], mn[p][r - (1 << p) + 1]).second;
}

int lca(int u, int v) {
	return getmin(min(L[u], L[v]), max(R[u], R[v]));
}

int Plus[maxn], Minus[maxn], sum[maxn];

int dfs3(int v, int p = -1) {
	int cur = 0;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i].first != p) cur += dfs3(e[v][i].first, v);
	cur += Plus[v];
	cur -= Minus[v] / 2;
	if (!f[v]) sum[v] = cur;
	cur -= Minus[v] / 2;
	return cur;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		f[x] = 1;
	}
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back(make_pair(v, w));
		e[v].push_back(make_pair(u, w));
	}

	dfs1(1);
	dfs2(1, -1, -1);
	build();
	for (int i = 0; i < vct.size(); i++) {
		int v = lca(vct[i].first, vct[i].second);
		Minus[v] += 2;
		Plus[vct[i].first]++;
		Plus[vct[i].second]++;
	}
	memset(sum, -1, sizeof(sum));
	dfs3(1);

	int cmx = -1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (sum[i] > cmx) {
			cnt = 0;
			cmx = sum[i];
		}
		if (sum[i] == cmx) cnt++;
	}
	cout << cmx << " " << cnt << endl;

	return 0;
}