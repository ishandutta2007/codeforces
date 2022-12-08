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

const ll N = 15;
const ll T = 225;
ll dp[T + 1][1 << N][3];

void sm(ll& a, ll b) {
	a += b;
	a %= mod;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, T;
	cin >> n >> T;
	vector<pair<int, int>> sg(n);
	for (int i = 0; i < n; i++) {
		cin >> sg[i].first >> sg[i].second;
		sg[i].second--;
		if (sg[i].first <= T) dp[sg[i].first][1 << i][sg[i].second] = 1;
	}
	ll ans = 0;
	for (int i = 0; i <= T; i++) {
		for (int mask = 1; mask < (1 << n); mask++) {
			for (int j = 0; j < n; j++) {
				if (sg[j].first > i) continue;
				if (!(mask & (1 << j))) continue;
				if (sg[j].second == 2) sm(dp[i][mask][2], dp[i - sg[j].first][mask - (1 << j)][0] + dp[i - sg[j].first][mask - (1 << j)][1]);
				if (sg[j].second == 0) sm(dp[i][mask][0], dp[i - sg[j].first][mask - (1 << j)][1] + dp[i - sg[j].first][mask - (1 << j)][2]);
				if (sg[j].second == 1) sm(dp[i][mask][1], dp[i - sg[j].first][mask - (1 << j)][0] + dp[i - sg[j].first][mask - (1 << j)][2]);
			}
			if (i == T) {
				sm(ans, dp[i][mask][0] + dp[i][mask][1] + dp[i][mask][2]);
			}
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}