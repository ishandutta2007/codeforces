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

int C[1001][1001];

void fill() {
	for (int i = 0; i <= 1000; i++) {
		C[i][0] = 1;
		C[i][i] = 1;
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<ll> a(n);
	fill();
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> dp(n);
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cur += dp[i - 1];
			cur = cur % mod;
		}
		if (a[i] <= 0 || (i + a[i] >= n)) continue;
		ll f1 = a[i] - 1;
		ll f2 = a[i] - 1;
		for (int j = i + a[i]; j < n; j++) {
			dp[j] += ((cur + 1) * (C[f1][f2] % mod)) % mod;
			dp[j] %= mod;
			f1++;
			//cout << dp[j] << " " << j << endl;
		}
		//cout << dp[i] << " aaa " << i << endl;
	}
	cur += dp[n - 1];
	cur %= mod;
	cout << cur << endl;
	//system("pause");
	return 0;
}