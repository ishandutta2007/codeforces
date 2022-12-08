#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;


typedef long long ll;

const ll INF = 1e18;


int main() {
	ll n;
	cin >> n;
	vector<ll> a(n / 2);
	cin >> a[0];
	vector<ll> ans(n);
	ans[0] = 0;
	ans[n - 1] = a[0];
	for (int i = 1; i < n / 2; i++) {
		cin >> a[i];
		ll t1 = ans[i - 1];
		ll t2 = a[i] - ans[i - 1];
		ll t21 = a[i] - ans[n - i];
		ll t22 = ans[n - i];
		if (t22 < t2) {
			ans[i] = t21;
			ans[n - i - 1] = t22;
		}
		else {
			ans[i] = t1;
			ans[n - i - 1] = t2;
		}
	}
	for (ll i : ans) {
		cout << i << " ";
	}
	//system("pause");
	return 0;
}