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
const ll mod1 = 1e9 + 7;
const ll mod2 = 777777773;
//const ll mod2 = 998244353;

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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, int>> f(n);
		unordered_map<int, int> lol;
		vector<int> kek;
		for (int i = 0; i < n; i++) {
			cin >> f[i].first >> f[i].second;	
			f[i].first *= 2;
			f[i].second *= 2;
			kek.push_back(f[i].first - 1);
			kek.push_back(f[i].first);
			kek.push_back(f[i].first + 1);
			kek.push_back(f[i].second - 1);
			kek.push_back(f[i].second);
			kek.push_back(f[i].second + 1);
		}
		sort(all(kek));
		kek.erase(unique(all(kek)), kek.end());
		for (int i = 0; i < kek.size(); i++) {
			lol[kek[i]] = i;
		}
		for (int i = 0; i < n; i++)
			f[i] = { lol[f[i].first], lol[f[i].second] };
		vector<pair<vector<int>, vector<int>>> cnt(kek.size());
		vector<bool> is(kek.size());
		for (int i = 0; i < n; i++) {
			cnt[f[i].first].first.push_back(i);
			cnt[f[i].second + 1].second.push_back(i);
		}
		vector<int> h(kek.size());
		int cur = 0;
		int tot = 0;
		set<int> current;
		vector<int> good(kek.size(),-1);
		vector<pair<pair<int, int>, int>> ed;
		for (int i = 0; i < kek.size(); i++) {
			if (cur && cur == cnt[i].second.size())
				tot++;
			for (int j : cnt[i].first)
				current.insert(j);
			for (int j : cnt[i].second)
				current.erase(j);
			cur += cnt[i].first.size() - cnt[i].second.size();
			h[i] = cur;
			if (h[i] == 1)
				good[i] = *current.begin();
			//cout << i << " " << good[i] << endl;
			if (good[i] != -1) {
				if (good[i - 1] == good[i])
					ed.back().first.second++;
				else
					ed.push_back({ {i, i}, good[i] });
			}
		}
		vector<int> ans(n);
		for (auto u : ed) {
			if ((h[u.first.first - 1] != 0) == (h[u.first.second + 1] != 0)) {
				if (h[u.first.first - 1] == 0)
					ans[u.second]--;
				else
					ans[u.second]++;
			}
		}
		int m = ans[0];
		for (int i = 0; i < n; i++) {
			m = max(m, ans[i]);
		}
		cout << tot + m << endl;
	}
	return;
}