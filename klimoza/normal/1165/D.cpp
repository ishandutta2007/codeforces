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
ll mod = 998244353;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
	return x.first * x.second < y.first * y.second;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> d(n);
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		sort(d.begin(), d.end());
		ll an = d[0] * d[n - 1];
		int l = 0;
		int r = n - 1;
		bool fl = true;
		for (int i = 2; i <= sqrt(an); i++) {
			if (an % i) continue;
			if (d[l] != i || d[r] != an / i) {
				fl = false;
				break;
			}
			l++;
			r--;
		}
		if (!fl || (l <= r)) {
			cout << -1 << endl;
		}
		else {
			cout << an << endl;
		}
	}
	//system("pause");
	return 0;
}