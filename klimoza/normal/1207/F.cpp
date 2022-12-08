#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <complex>

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 998244353;
void solve();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 5e5 + 7;
const int K = 710;

int b[K][K];
int a[N];

void solve() {
	int t; cin >> t;
	ll x, y;
	while (t--) {
		int n; cin >> n;
		if (n == 1) {
			cin >> x >> y;
			for (int i = 1; i < K; i++) {
				b[i][x % i] += y;
			}
			a[x] += y;
		}
		else {
			cin >> x >> y;
			if (x >= K) {
				ll ans = 0;
				for (int i = y; i < N; i += x) {
					ans += a[i];
				}
				cout << ans << '\n';
			}
			else {
				cout << b[x][y] << '\n';
			}
		}
	}
}