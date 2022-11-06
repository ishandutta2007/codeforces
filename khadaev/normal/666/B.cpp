#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif

const ld eps = 1e-9;
const int INF = 100000;
const int N = 3000;
vector<int> e[N];
int d[N][N];
pair<int, int> maxd[N];

pair<int, int> bfs(int i) {
	int used[N];
	forn(i, 0, N) used[i] = 0;
	vector<int> now = {i}, next;
	used[i] = 1;
	int dist = 0;
	while (!now.empty()) {
		next.clear();
		for (int j : now) d[i][j] = dist;
		for (int j : now)
			for (int to : e[j])
				if (!used[to]) {
					used[to] = 1;
					next.eb(to);
				}
		++dist;
		next.swap(now);
	}
	if (next.size() == 1) return {dist - 1, next[0]};
	else return {dist - 1, -1};
}

int check(int a[]) {
	forn(i, 0, 4) if (a[i] == -1) return INF;
	forn(i, 0, 4) forn(j, 0, 4) if (i != j && a[i] == a[j]) return INF;
	int ans = 0;
	forn(i, 0, 3) ans += d[a[i]][a[i + 1]];
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, 0, n) forn(j, 0, n) d[i][j] = INF;
	forn(i, 0, m) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		e[u].eb(v);
	}
	forn(i, 0, n) maxd[i] = bfs(i);
	int ans = 0, ansp[4];
	int vl[N][3], vr[N][3];
	forn(i, 0, n) {
		int c = 0;
		int dist = 0;
		forn(j, 0, n) {
			if (d[i][j] != INF) dist = max(dist, d[i][j]);
		}
		while (c < 3) {
			forn(j, 0, n) {
				if (d[i][j] == dist) {
					vr[i][c] = j;
					++c;
				}
				if (c > 3) break;
			}
			dist--;
			if (dist < 0) {
				forn(j, c, 3) vr[i][j] = -1;
				break;
			}
		}
		c = 0;
		dist = 0;
		forn(j, 0, n) {
			if (d[j][i] != INF) dist = max(dist, d[j][i]);
		}
		while (c < 3) {
			forn(j, 0, n) {
				if (d[j][i] == dist) {
					vl[i][c] = j;
					++c;
				}
				if (c > 3) break;
			}
			dist--;
			if (dist < 0) {
				forn(j, c, 3) vl[i][j] = -1;
				break;
			}

		}
	}
	forn(i, 0, n) forn(j, 0, n) forn(k, 0, 3) forn(t, 0, 3) {
		int locansp[4] = {vl[i][k], i, j, vr[j][t]};
		int locans = check(locansp);
		if (locans < INF && locans > ans) {
			ans = locans;
			forn(q, 0, 4) ansp[q] = locansp[q];
		}
	}
	forn(i, 0, 4) cout << 1 + ansp[i] << ' ';
	return 0;
}