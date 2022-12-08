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
#include <string>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
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

const int N = 1e5 + 2;

vector<int> g[N];
//vector<int> ng[N];
unordered_set<int> sg[N];

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		vector<int> sz(n);
		for (int i = 0; i < n; i++) {
			g[i].clear();
			//ng[i].clear();
			sg[i].clear();
		}
		vector<bool> del(n, false);
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b; a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
			sg[a].insert(b);
			sg[b].insert(a);
			sz[a]++; sz[b]++;
		}
		if (k == 1) {
			cout << "2\n1\n";
			continue;
		}
		if (k * 1ll * (k - 1) > 2 *1ll* m) {
			cout << -1 << endl;
			continue;
		}
		set<pair<int, int>> kek;
		for (int i = 0; i < n; i++)
			kek.insert(mp(sz[i], i));
		bool bl = false;
		while (!kek.empty()) {
			auto v = *kek.begin();
			if (v.first < k - 1) {
				kek.erase(kek.begin());
				del[v.second] = true;
				for (int u : g[v.second]) {
					if (del[u]) continue;
					sg[v.second].erase(u);
					sg[u].erase(v.second);
					kek.erase(kek.find(mp(sz[u], u)));
					sz[u]--;
					kek.insert(mp(sz[u], u));
				}
			}
			else if (v.first >= k) break;
			else {
				vector<int> tmp;
				for (int i : g[v.second])
					if (!del[i])
						tmp.push_back(i);
				bool fl = true;
				for (int i = 0; i < tmp.size(); i++) {
					for (int j = i + 1; j < tmp.size(); j++) {
						if (!fl) break;
						if (sg[tmp[i]].find(tmp[j]) == sg[tmp[i]].end()) {
							fl = false;
							break;
						}
					}
					if (!fl) break;
				}
				if (fl) {
					cout << "2\n";
					cout << v.second + 1 << " ";
					for (int i : tmp)
						cout << i + 1 << " ";
					cout << endl;
					bl = true;
					break;
				}
				else {
					kek.erase(kek.begin());
					del[v.second] = true;
					for (int u : g[v.second]) {
						if (del[u]) continue;
						sg[v.second].erase(u);
						sg[u].erase(v.second);
						kek.erase(kek.find(mp(sz[u], u)));
						sz[u]--;
						kek.insert(mp(sz[u], u));
					}
				}
			}
		}
		if (bl) continue;
		if (kek.empty()) {
			cout << -1 << endl;
			continue;
		}
		cout << 1 << " " << (kek.size()) << endl;
		for (auto u : kek)
			cout << u.second + 1 << " ";
		cout << endl;
		//if (kek.empty()) {
		//	cout << -1 << endl;
		//	continue;
		//}
		//vector<pair<int, int>> lol;
		//for (auto u : kek) {
		//	lol.push_back(u);
		//	for (int v : g[u.second])
		//		if (!del[v]) {
		//			ng[u.second].push_back(v);
		//			sg[u.second].insert(v);
		//		}
		//	sort(all(ng[u.second]), [&](int x, int y) {return sz[x] < sz[y]; });
		//}
		//vector<int> pos(n, -1);
		//for (int i = 0; i < lol.size(); i++)
		//	pos[lol[i].second] = i;
		//vector<pair<int, int>> c(n, mp(-1, 0));
		//for (int i = 0; i < lol.size(); i++) {
		//	pair<int, int> u = lol[i];
		//	if (u.first >= k) break;
		//	for (int j : ng[u.second]) {
		//		for (int h : ng[u.second]) {

		//		}
		//	}
		//	/*if (c[u.second].first != -1) continue;
		//	c[u.second] = mp(i, 0);
		//	int cur = 0;
		//	vector<int> ans;
		//	bool fl = true;
		//	for (int j = i; j < lol.size(); j++) {
		//		pair<int, int> v = lol[j];
		//		if (c[v.second].first < i) continue;
		//		if (c[v.second].second < cur) continue;
		//		cur++;
		//		ans.push_back(v.second);
		//		if (sz[v.second] == k - 1) {
		//			for (int h : ng[v.second]) {
		//				if (pos[h] < j && c[h].first < i) {
		//					fl = false;
		//					break;
		//				}
		//				if (pos[h] < j) continue;
		//				if (c[h].first < i) c[h] = mp(i, 1);
		//				else c[h].second++;
		//			}
		//		}
		//		if (!fl) break;
		//	}
		//	if (!fl) continue;*/

		//}
	}
	return;
}