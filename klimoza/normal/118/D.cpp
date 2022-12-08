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
ll mod = 1e8;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	vector<vector<pair<ll, ll>>> dp(n1 + 1, vector<pair<ll, ll>>(n2 + 1));
	dp[0][0].first = 1;
	dp[0][0].second = 1;
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			for (int k = 1; k <= min(i, k1); k++) {
				dp[i][j].first += dp[i - k][j].second;
				dp[i][j].first %= mod;
			}
			for (int k = 1; k <= min(j, k2); k++) {
				dp[i][j].second += dp[i][j - k].first;
				dp[i][j].second %= mod;
			}
		}
	}
	
	cout << (dp[n1][n2].first + dp[n1][n2].second) % mod << endl;
	//system("pause");
	return 0;
}