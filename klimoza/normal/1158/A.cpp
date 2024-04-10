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
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a[n - 1] > b[0]) {
		cout << -1 << endl;
	}
	else {
		ll ans = 0;
		for (int i = 0; i < n - 1; i++) ans += m * a[i];
		ll su = 0;
		for (int i = 0; i < m; i++) su += b[i];
		if (b[0] == a[n - 1]) {
			ans += su;
			cout << ans << endl;
		}
		else {
			if (m == 1 || n == 1) {
				cout << -1 << endl;
			}
			else {
				ans -= a[n - 2];
				ans += su + a[n - 1];
				cout << ans << endl;
			}
		}
	}
	//system("pause");
	return 0;
}