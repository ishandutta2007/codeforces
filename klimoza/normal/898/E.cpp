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
long double eps = 1e-8;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt0 = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!a[i]) cnt0++;
		//cout << sqrt(a[i]) << endl;
		a[i] = min(a[i] - (int)sqrt(a[i]) * (int)sqrt(a[i]), ((int)sqrt(a[i]) + 1) * ((int)sqrt(a[i]) + 1) - a[i]);
		//cout << a[i] << "  --- " << endl;
		if (!a[i]) cnt++;
	}
	sort(a.begin(), a.end());
	if (cnt <= n / 2) {
		ll ans = 0;
		for (int i = 0; i < n / 2; i++) {
			ans += a[i];
		}
		cout << ans << endl;
	}
	else {
		int cnt1 = cnt - cnt0;
		if (cnt1 >= (cnt - n / 2)) {
			cout << cnt - n / 2 << endl;
		} else{
			cout << cnt1 + (cnt0 - n / 2) * 2 << endl;
		}
	}
	//system("pause");
	return 0;
}