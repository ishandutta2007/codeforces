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
	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	vector<pair<ll, ll>> dp(n);
	dp[0].first = a[0];
	dp[0].second = b[0];
	ll ans1 = a[0];
	ll ans2 = b[0];
	for (int i = 1; i < n; i++) {
		dp[i].first = ans2 + a[i];
		dp[i].second = ans1 + b[i];
		ans1 = max(ans1, dp[i].first);
		ans2 = max(ans2, dp[i].second);
	}
	cout << max(ans1, ans2) << endl;
	return 0;
}