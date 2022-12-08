#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 998244353;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	set<int>::iterator it1, it2;
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> suff;
	vector<pair<int, int>> pref;
	set<int> r;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	r.insert(a[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		r.insert(a[i]);
		it2 = r.lower_bound(a[i]);
		it1 = r.lower_bound(0);
		if (*it1 != a[i]) {
			it2--;
			pref.push_back({ *it1, *it2 });
			suff.push_back({ (*it1) + 1, a[i] });
			suff.push_back({ a[i] + 1, x + 1 });
		}
	}
	sort(pref.begin(), pref.end());
	sort(suff.begin(), suff.end());
	vector<int> l(x + 1);
	int maxi = 1;
	int ind = pref.size() - 1;
	for (int i = x; i >= 1; i--) {
		while (ind >= 0 && pref[ind].first >= i) {
			maxi = max(maxi, pref[ind--].second);
		}
		l[i] = max(maxi, i);
	}
	maxi = 1;
	ind = 0;
	ll ans = 0;
	for (int i = 1; i <= x; i++) {
		while (ind < suff.size() && suff[ind].first <= i) {
			maxi = max(maxi, suff[ind++].second);
		}
		l[i] = max(maxi, l[i]);
		ans += x - l[i] + 1;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}