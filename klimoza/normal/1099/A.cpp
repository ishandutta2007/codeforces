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

	int w, h, u1, d1, u2, d2;
	cin >> w >> h >> u1 >> d1 >> u2 >> d2;
	ll ans = w;
	for (int i = h; i >= 0; i--) {
		ans += i;
		if (i == d1) ans -= u1;
		if (i == d2) ans -= u2;
		ans = max(ans, (ll)0);
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}