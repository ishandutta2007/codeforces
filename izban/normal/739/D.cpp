#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;
#define tm ttm

using namespace std;

const int MAXK = -1;
const int MAXN = 602;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n;
int pc[MAXN];
int c[MAXN];
int nxt[MAXN];

void read(int &x) {
	string s;
	cin >> s;
	if (s == "?") {
		x = -1;
		return;
	}
	stringstream ss;
	ss << s;
	ss >> x;
}
vector<pair<int, int> > o;

bool eq(int x, int y) {
	return x == y || y == -1;
}

vector<int> e[MAXN];
int mt[MAXN], tm[MAXN];
int vis[MAXN], tmr;

bool dfs(int v) {
	if (vis[v] == tmr) return 0;
	vis[v] = tmr;
	for (int to : e[v]) {
		if (mt[to] == -1) {
			mt[to] = v;
			tm[v] = to;
			return 1;
		}
	}
	for (int to : e[v]) {
		if (dfs(mt[to])) {
			mt[to] = v;
			tm[v] = to;
			return 1;
		}
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			read(pc[i]);
			read(c[i]);
			nxt[i] = -1;
		}
		map<int, map<int, vector<int> > > mp;

		for (int i = 0; i < n; i++) {
			mp[c[i]][pc[i]].push_back(i);
		}

		bool ok = 0;

		int nmx = 0;
		if (mp.count(-1)) {
			nmx = max(0, mp[-1].rbegin()->first);
		}

		vector<int> mx(n + 1, -1);
		for (int i = 1; i <= n; i++) {
			if (!mp.count(i)) continue;
			mx[i] = mp[i].rbegin()->first;
		}

		for (int nc = 1; nc <= n; nc++) {
			bool wasnt = !mp.count(nc);
			mp[nc];
			int old = mx[nc];
			mx[nc] = max(mx[nc], nmx);

			o.clear();
			for (int cc = 1; cc <= n; cc++) {
				if (!mp.count(cc)) continue;
				vector<int> vct = mp[cc][0];
				vector<int> vv;
				vector<vector<int> > cycles;
				for (int x : vct) {
					if (vv.size() == cc) {
						for (int i = 0; i < (int)vv.size(); i++) nxt[vv[i]] = vv[(i + 1) % vv.size()];
						cycles.push_back(vv);
						vv.clear();
					}
					vv.push_back(x);
				}
				for (int i = 0; i < cc - (int)vv.size(); i++) {
					o.push_back(make_pair(0, cc));
				}
				for (int i = 1; i <= mx[cc]; i++) {
					if (!mp[cc].count(i)) {
						o.push_back(make_pair(i, cc));
					}
				}
			}
			int m = o.size();
			for (int i = 0; i < m; i++) {
				e[i].clear();
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if ((pc[i] == -1 || c[i] == -1) && eq(o[j].first, pc[i]) && eq(o[j].second, c[i])) {
						//e[i].push_back(j);
						e[j].push_back(i);
					}
				}
			}
			for (int i = 0; i < n; i++) {
				mt[i] = -1;
			}
			for (int i = 0; i < m; i++) {
				tm[i] = -1;
			}
			/*bool cok = 1;
			for (int i = 0; cok && i < m; i++) {
			memset(vis, 0, sizeof(vis));
			cok &= dfs(i);
			}*/
			for (int run = 1; run;) {
				run = 0;
				tmr++;
				for (int i = 0; i < m; i++) {
					if (tm[i] == -1 && dfs(i)) {
						run = 1;
					}
				}
			}
			bool cok = 1;
			for (int i = 0; i < m; i++) cok &= tm[i] != -1;

			if (cok) {
				for (int i = 0; i < n; i++) {
					//pc[mt[i]] = o[i].first;
					//c[mt[i]] = o[i].second;
					if (mt[i] != -1) {
						pc[i] = o[mt[i]].first;
						c[i] = o[mt[i]].second;
					}
				}
				ok = 1;
				break;
			}
			mx[nc] = old;
			if (wasnt) mp.erase(nc);
		}

		if (ok) {
			vector<vector<int> > vv(n + 1);
			for (int i = 0; i < n; i++) {
				if (nxt[i] == -1 && pc[i] == 0 && c[i] != -1) {
					vv[c[i]].push_back(i);
				}
			}
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j < (int)vv[i].size(); j++) {
					nxt[vv[i][j]] = vv[i][(j + 1) % vv[i].size()];
				}
			}
			int mxc = 0;
			for (int i = 0; i <= n; i++) if (mx[i] > mx[mxc]) mxc = i;
			for (int i = 0; i < n; i++) {
				if (nxt[i] != -1) continue;
				if ((c[i] == -1 || c[i] == 1) && pc[i] == 0) {
					nxt[i] = i;
					continue;
				}
				if (pc[i] == -1) pc[i] = 1;
				if (c[i] == -1) {
					//c[i] = mp.rbegin()->first;
					c[i] = mxc;
				}
				for (int j = 0; j < n; j++) {
					if (c[j] == c[i] && pc[j] + 1 == pc[i]) {
						nxt[i] = j;
						break;
					}
				}
				assert(nxt[i] != -1);
			}
			for (int i = 0; i < n; i++) cout << nxt[i] + 1 << " \n"[i + 1 == n];
		}
		else {
			cout << -1 << endl;
		}
	}

	return 0;
}