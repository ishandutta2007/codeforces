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

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;
	map<ll, int> cnt;
	ll cnt1 = 0;
	ll su = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
		if (cnt[a[i]] == 2) cnt1++;
		if (cnt[a[i]] == 3 || (cnt[a[i]] == 2 && a[i] == 0)) {
			cout << "cslnb\n";
			return 0;
		}
	}
	if (cnt1 > 1) {
		cout << "cslnb\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] >= 2 && cnt[a[i] - 1] > 0) {
			cout << "cslnb\n";
			return 0;
		}
	}
	for (ll i = 0; i < n; i++) {
		su += a[i] - i;
	}
	if (su % 2 == 0) cout << "cslnb\n";
	else cout << "sjfnb\n";
	return 0;
}