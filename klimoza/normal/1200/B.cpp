#define _CRT_SECURE_NO_WARNINGS
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

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod = 998244353;

mt19937 mrand(random_device{} ());


signed main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	

	int t;
	cin >> t;
	while (t--) {
		ll n, m, k;
		cin >> n >> m >> k;
		vector<int> h(n);
		for (int i = 0; i < n; i++) cin >> h[i];
		bool fl = true;
		for (int i = 0; i < n - 1; i++) {
			int point = max((ll)0, h[i + 1] - k);
			if (point >= h[i]) {
				int cnt = point - h[i];
				//cout << cnt << " " << i << " " << m << " " << point << endl;
				if (cnt > m) {
					fl = false;
					break;
				}
				else {
					m -= cnt;
					continue;
				}
			}
			else {
				m += h[i] - point;
			}
		}
		if (fl) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}