#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<ll, ll>> pref((1 << 20));
	ll cur = 0;
	ll t;
	ll ans = 0;
	pref[0].second++;
	for (int i = 0; i < n; i++) {
		cin >> t;
		cur = cur ^ t;
		//cout << cur << " " << i << endl;
		if (i % 2 == 0) {
			ans += pref[cur].first;
			pref[cur].first++;
		}
		else {
			ans += pref[cur].second;
			pref[cur].second++;
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}