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
ll mod = 998244353;

int pw(int x, int p) {
	if (p <= 0) return 1;
	return pw(x, p - 1) * x;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	vector<pair<int, ll>> f(m);
	cin >> f[0].first >> f[0].second;
	ll maxi = f[0].second + (f[0].first - 1);
	for (int i = 1; i < m; i++) {
		cin >> f[i].first >> f[i].second;
		if (f[i].second <= f[i - 1].second) {
			ll h = f[i].first - (f[i - 1].second - f[i].second);
			if (h < f[i - 1].first) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			else {
				maxi = max(f[i - 1].second + (h - f[i - 1].first) / 2, maxi);
			}
		}
		else {
			swap(f[i].second, f[i - 1].second);
			ll h = f[i].first - (f[i - 1].second - f[i].second);
			if (h < f[i - 1].first) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			else {
				maxi = max(f[i - 1].second + (h - f[i - 1].first) / 2, maxi);
			}
			swap(f[i].second, f[i - 1].second);
		}
	}
	maxi = max(maxi, n - f[m - 1].first + f[m - 1].second);
	cout << maxi << endl;
	//system("pause");
	return 0;
}