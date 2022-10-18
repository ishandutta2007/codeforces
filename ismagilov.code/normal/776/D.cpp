#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd ; exit(0)

using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
bool a[MAXN];
set<int> zap[MAXN];
bool used[MAXN];
bool used1[MAXN];
vector<int> mem[MAXN];
bool prav = 1;


void dfs(int v) {
	for (auto to : zap[v]) {
		if (!used[to]) {
			used[to] = 1;
			if (!a[v]) {
				used1[to] = 1;
				for (auto gg : mem[to]) {
					a[gg] = !a[gg];
				}
			}
			for (auto gg : mem[to]) {
				dfs(gg);
			}
		}
	}
	if (!a[v]) {
		prav = 0;
	}
}

void dfs1(int v) {
	for (auto to : zap[v]) {
		if (used[to]) {
			used[to] = 0;
			if (used1[to]) {
				used1[to] = 0;
				for (auto gg : mem[to]) {
					a[gg] = !a[gg];
				}
			}
			for (auto gg : mem[to]) {
				dfs1(gg);
			}
		}
	}
}

main() {
	//freopen("kek.in", "r", stdin);
	//freopen("kek.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int d;
			cin >> d;
			d--;
			mem[i].pb(d);
			zap[d].insert(i);
		}
	}
	for (int to = 0; to < m; to++) {
		if (!used[to]) {
			prav = 1;
			used[to] = 1;
			used1[to] = 1;
			for (auto gg : mem[to]) {
				a[gg] = !a[gg];
			}
			for (auto gg : mem[to]) {
				dfs(gg);
			}
			if (!prav) {
				prav = 1;
				used[to] = 0;
				used1[to] = 0;
				for (auto gg : mem[to]) {
					a[gg] = !a[gg];
				}
				for (auto gg : mem[to]) {
					dfs1(gg);
				}
				used[to] = 1;
				for (auto gg : mem[to]) {
					dfs(gg);
				}
				if (!prav) {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!a[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}