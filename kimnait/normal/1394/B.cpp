#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define make_pair MP
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = (int)1e9 + 7;

const int N = (int)1e6 + 7;
vector<pair<int, int>> edge[ N ], st[ N ];
bool gg[10][10];
bool hv[10][10][10][10];
int cnt[10][10];
int ans;
vector<pair<int, int>> E[10][10];
void go(int ll, int rr) {
	if (ll > rr) { ans++; return ; }
	for (int i = 1; i <= ll; i++) {
		if (gg[ll][i]) continue ;
		if (cnt[ll][i]) continue ;
		for (auto x : E[ll][i]) {
			cnt[x.first][x.second]++;
		}
		go(ll + 1, rr);
		for (auto x : E[ll][i]) {
			cnt[x.first][x.second]--;
		}
	}
}
int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		edge[u].push_back({w, v});
	}
	for (int i = 1; i <= n; i++) {
		sort(edge[i].begin(), edge[i].end());
		for (int j = 0; j < SZ(edge[i]); j++) {
			st[ edge[i][j].second ].push_back({SZ(edge[i]), j + 1});
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(st[i].begin(), st[i].end());
		for (int j = 0; j < SZ(st[i]); j++) {
			if (j && st[i][j] == st[i][j-1]) gg[ st[i][j].first ][ st[i][j].second ] = true;
		}
		st[i].resize(unique(st[i].begin(), st[i].end()) - st[i].begin());
		for (int p1 = 0; p1 < SZ(st[i]); p1++) {
			for (int p2 = p1 + 1; p2 < SZ(st[i]); p2++) {
				if (hv[ st[i][p1].F ][ st[i][p1].S ][ st[i][p2].F ][ st[i][p2].S ]) continue ;
				hv[ st[i][p1].F ][ st[i][p1].S ][ st[i][p2].F ][ st[i][p2].S ] = true;
				E[ st[i][p1].first ][ st[i][p1].second ].push_back(st[i][p2]);
			}
		}
	}
	go(1, k);
	printf("%d\n", ans);
	return 0;
}