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
const ll mod = 1e9 + 7;

mt19937 mrand(random_device{} ());

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	int t;
	vector<int> a(k + 1);
	int cnt = (n + 1) / 2;
	while (n--) {
		cin >> t;
		a[t]++;
	}
	for (int i = 0; i <= k; i++) {
		while (a[i] > 1) {
			ans += 2;
			a[i] -= 2;
			cnt--;
			if (!cnt) break;
		}
		if (!cnt) break;
	}
	for (int i = 0; i <= k; i++) {
		if (!cnt) break;
		if (a[i]) {
			a[i]--;
			cnt--;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}