#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> a(n);
	ll cur = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ll x = min(a[i] / 2, cur);
		cur -= x;
		a[i] -= 2 * x;
		ans += x;
		ans += a[i] / 3;
		cur += a[i] % 3;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}