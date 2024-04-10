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
#include <bitset>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

const int K = 61;
const int N = 512;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		vector<pair<pair<int, int>, int> > edges(m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &edges[i].first.first, &edges[i].first.second, &edges[i].second);
			edges[i].first.first--;
			edges[i].first.second--;
		}

		vector<vector<vector<bitset<N> > > > e(K, vector<vector<bitset<N> > >(2, vector<bitset<N>>(n)));
		for (int i = 0; i < m; i++) {
			e[0][edges[i].second][edges[i].first.first][edges[i].first.second] = 1;
		}

		for (int t = 1; t < K; t++) {
			for (int f = 0; f < 2; f++) {
				for (int k = 0; k < n; k++) {
					for (int i = 0; i < n; i++) {
						if (e[t - 1][f][i][k]) {
							e[t][f][i] |= e[t - 1][f ^ 1][k];
						}
					}
				}
			}
		}

		bool inf = 0;
		for (int f = 0; f < 2; f++) {
			for (int j = 0; j < n; j++) {
				if (e[K - 1][0][0][j]) {
					inf = 1;
				}
			}
		}
		ll ans = 0;
		if (inf) ans = -1;
		else {
			ans = 0;
			vector<int> can(n);
			can[0] = 1;
			int type = 0;
			for (int t = K - 1; t >= 0; t--) {
				vector<int> ncan(n);
				for (int i = 0; i < n; i++) if (can[i]) {
					for (int j = 0; j < n; j++) {
						if (e[t][type][i][j]) {
							ncan[j] = 1;
						}
					}
				}
				bool any = 0;
				for (int i = 0; i < n; i++) any |= ncan[i];
				if (any) {
					ans += 1LL << t;
					can = ncan;
					type ^= 1;
				}
			}
		}
		if (ans > (ll)1e18) ans = -1;
		cout << ans << endl;
	}

	return 0;
}