#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
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
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

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

struct Item {
	int a, b, c;
	Item() {}
	Item(int a, int b, int c) : a(a), b(b), c(c) {}
};

void norm(Item &x) {
	int g[3] = { x.a, x.b, x.c };
	sort(g, g + 3);
	x.a = g[0]; x.b = g[1]; x.c = g[2];
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<Item> p(n - 2);
		set<pair<int, int>> f;
		map<pair<int, int>, int> c;
		vector<int> cnt(n);
		set<pair<int, int>> kek;
		vector<vector<int>> lol(n);
		for (int i = 0; i < (n - 2); i++){
			cin >> p[i].a >> p[i].b >> p[i].c;
			p[i].a--; p[i].b--; p[i].c--;
			norm(p[i]);
			cnt[p[i].a]++;
			cnt[p[i].b]++;
			cnt[p[i].c]++;
			lol[p[i].a].push_back(i);
			lol[p[i].b].push_back(i);
			lol[p[i].c].push_back(i);
			f.insert({ p[i].a, p[i].b });
			f.insert({ p[i].a, p[i].c });
			f.insert({ p[i].b, p[i].c });
			c[{p[i].a, p[i].b}] += 1;
			c[{p[i].a, p[i].c}] += 1;
			c[{p[i].b, p[i].c}] += 1;
		}
		vector<vector<int>> h(n);
		for (auto u : f) {
			//cout << u.first << " " << u.second << " " << c[u] << endl;
			if (c[u] == 1) {
				h[u.first].push_back(u.second);
				h[u.second].push_back(u.first);
			}
		}
		vector<int> ans;
		int s = 0, last = -1, cur = 0;
		while (true) {
			ans.push_back(cur + 1);
			if (h[cur][0] != last) {
				if (h[cur][0] == s) break;
				last = cur;
				cur = h[cur][0];
				continue;
			}
			else {
				if (h[cur][1] == s) break;
				last = cur;
				cur = h[cur][1];
				continue;
			}
		}
		vector<bool> used(n - 2, false);
		vector<int> ans2;
		for (int i = 0; i < n; i++) {
			kek.insert({ cnt[i], i });
		}
		while (!kek.empty()) {
			auto v = *kek.begin();
			if (!v.first) continue;
			for (int i = 0; i < lol[v.second].size(); i++) {
				if (!used[lol[v.second][i]]) {
					int id = lol[v.second][i];
					kek.erase({ cnt[p[id].a], p[id].a });
					cnt[p[id].a]--;
					if(cnt[p[id].a])
					kek.insert({ cnt[p[id].a], p[id].a });
					kek.erase({ cnt[p[id].b], p[id].b });
					cnt[p[id].b]--;
					if(cnt[p[id].b])
					kek.insert({ cnt[p[id].b], p[id].b });
					kek.erase({ cnt[p[id].c], p[id].c });
					cnt[p[id].c]--;
					if(cnt[p[id].c])
					kek.insert({ cnt[p[id].c], p[id].c });
					ans2.push_back(id + 1);
					used[id] = true;
				}
			}
		}
		for (int i : ans) cout << i << " ";
		cout << endl;
		for (int i : ans2) cout << i << " ";
		cout << endl;
	}
	return;
}