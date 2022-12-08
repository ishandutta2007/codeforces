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

mt19937 mrand(239);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			b[i]--;
		}
		vector<int> a(n, -1);
		vector<vector<int>> cnt(n + 1, vector<int>());
		set<pair<int, int>> f;
		for (int i = 0; i < n; i++) {
			cnt[b[i]].push_back(i);
		}
		for (int i = 0; i < n + 1; i++) {
			if (!cnt[i].empty())
				f.insert({ cnt[i].size(), i });
		}
		int sz = 0;
		while (sz < x) {
			auto v = *f.rbegin();
			f.erase(v);
			a[cnt[v.second].back()] = v.second;
			cnt[v.second].pop_back();
			v.first--;
			if (v.first)
				f.insert(v);
			sz++;
		}
		vector<int> kek(n + 1, 0);
		vector<pair<int, int>> mem;
		sz = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == -1) {
				kek[b[i]]++;
				mem.push_back({ b[i], i });
				sz++;
			}
		}
		/*for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;*/
		sort(all(mem));
		vector<pair<int, int>> lol = mem;
		vector<pair<int, int>> tmp;
		for (int i = 0; i < (n - x) / 2; i++) {
			tmp.push_back(mem.back());
			mem.pop_back();
		}
		reverse(all(tmp));
		for (auto u : mem)
			tmp.push_back(u);
		sz = 0;
		for (int i = 0; i < lol.size(); i++) {
			if (sz == y - x) break;
			if (lol[i].first == tmp[i].first) continue;
			sz++;
			a[lol[i].second] = tmp[i].first;
		}
		if (sz < (y - x)) cout << "NO\n";
		else {
			/*for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;*/
			set<int> kk;
			for (int i = 0; i < n + 1; i++) {
				kk.insert(i);
			}
			for (int i = 0; i < n; i++) {
				kk.erase(b[i]);
			}
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				if (a[i] == -1)
					a[i] = *kk.begin();
				cout << a[i] + 1 << " ";
			}
			cout << endl;
		}
	}
	return;
}