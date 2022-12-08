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

using namespace std;

typedef long long ll;

ll INF = 4e18;
ll INFi = 2e9;
long double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
	ll x, y, z;
	cin >> x >> y >> z;
	ll ans = 0;
	ans += x / z;
	ans += y / z;
	x = x % z;
	y = y % z;
	if (x + y >= z) {
		cout << ans + 1 << " " << z - max(x, y) << endl;
	}
	else {
		cout << ans << " " << 0 << endl;
	}
	return 0;
}