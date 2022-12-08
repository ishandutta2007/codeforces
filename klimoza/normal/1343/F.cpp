/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 201;

vector<int> g[N];

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fill(g, g + n, vector<int>());
		vector<set<int>> kek(n - 1);
		for (int i = 0; i < n - 1; i++) {
			int k; cin >> k;
			while (k--) {
				int t; cin >> t; t--;
				g[t].push_back(i);
				kek[i].insert(t);
			}
		}
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			vector<int> sz(n - 1);
			for (int i = 0; i < n - 1; i++)
				sz[i] = kek[i].size();
			set<pair<int, int>> f;
			for (int j = 0; j < n - 1; j++) {
				f.insert({ kek[j].size(), j });
			}
			bool fl = true;
			for (int j = 0; j < n; j++) {
				int d;
				if (j == 0) d = i;
				else {
					auto v = *f.begin();
					if (v.first != 1) {
						fl = false;
						//cout << i << " " << j << " " << v.first << " KEK\n";
						break;
					}
					int len = kek[v.second].size();
					bool bl = true;
					set<int> mem;
					for (int t = j - 1; t >= j - (len - 1); t--) {
						if (kek[v.second].find(ans[t]) == kek[v.second].end()) {
							bl = false;
							break;
						}
						mem.insert(ans[t]);
					}
					if (!bl) {
						fl = false;
						break;
					}
					for (int t : kek[v.second]) {
						if (mem.find(t) == mem.end()) {
							d = t;
							break;
						}
					}
				}
				ans[j] = d;
				//cout << i + 1 << " " << ans[j] + 1 << endl;
				for (int u : g[d]) {
					f.erase({ sz[u], u });
					sz[u]--;
					if(sz[u])
					f.insert({ sz[u], u });
				}
			}
			if (fl) {
				for (int i : ans)
					cout << i + 1 << " ";
				cout << endl;
				break;
			}
		}
	}
	return;
}