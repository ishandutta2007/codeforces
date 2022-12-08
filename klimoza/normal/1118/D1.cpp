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

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum < m) {
		cout << -1 << endl;
		return 0;
	}
	sort(a.begin(), a.end(), cmp);
	int l = 0;
	int r = n;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		ll sz = -1;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if (i % mid == 0) sz++;
			cnt += max((ll)0, (ll)a[i] - sz);
		}
		//cout << cnt << " " << mid << endl;
		if (cnt < m) l = mid;
		else r = mid;
	}
	cout << r << endl;
	//system("pause");
	return 0;
}