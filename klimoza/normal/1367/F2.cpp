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

mt19937 mrand(43);

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

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		vector<pair<int, int>> kek;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			kek.push_back({ a[i], i });
		}
		sort(all(kek));
		vector<int> cnt(n);
		cnt[n - 1] = 1;
		int ans = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			if (kek[i + 1].second > kek[i].second)
				cnt[i] = cnt[i + 1] + 1;
			else {
				int x = kek[i + 1].first;
				cnt[i] = 1;
				for (int j = i + 1; j < n; j++) {
					if (kek[j].first != x) break;
					if (kek[j].second > kek[i].second)
						cnt[i]++;
				}
			}
			//cout << kek[i].first << " " << kek[i].second << " " << cnt[i] << endl;
			ans = min(ans, n - cnt[i]);
			if (i && kek[i].first != kek[i - 1].first) {
				int x = kek[i - 1].first;
				int mem = 0;
				for (int j = i - 1; j >= 0; j--) {
					if (kek[j].first != x) break;
					if (kek[j].second < kek[i].second)
						mem++;
				}
				ans = min(ans, n - cnt[i] - mem);
			}
		}
		vector<pair<int, vector<int>>> lol;
		for (int i = 0; i < n; i++) {
			if (lol.empty() || lol.back().first != kek[i].first)
				lol.push_back({ kek[i].first, vector<int>() });
			lol.back().second.push_back(kek[i].second);
		}
		int m = lol.size();
		for (int i = 0; i < (m - 1); i++) {
			int r = lol[i + 1].second.size();
			int l = 1;
			int sz = lol[i + 1].second.size();
			for (; l <= lol[i].second.size(); l++) {
				while (r && lol[i + 1].second[sz - r] < lol[i].second[l - 1])
					r--;
				ans = min(ans, n - (l + r));
			}
		}
		cout << ans << endl;
	}
	return;

}