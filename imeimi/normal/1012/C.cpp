#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

void setMin(int &x, int y) {
    if (x > y) x = y;
}

const int inf = 1e9;
int n;
int a[5001];
int dp[5001][5001][3];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
        cin >> a[i];
	}
	for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j][0] = inf;
            dp[i][j][1] = inf;
            dp[i][j][2] = inf;
        }
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	dp[0][0][2] = 0;
	for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            setMin(dp[i][j][0], dp[i - 1][j][0]);
            setMin(dp[i][j][0], dp[i - 1][j][2]);
            
            setMin(dp[i][j][2], dp[i - 1][j][1] + max(a[i] - a[i - 1] + 1, 0));
            
            if (j == 0) continue;
            setMin(dp[i][j][1], dp[i - 1][j - 1][0] + max(a[i - 1] - a[i] + 1, 0));
            if (i < 3) continue;
            int pr = min(a[i - 2] - 1, a[i - 1]);
            setMin(dp[i][j][1], dp[i - 1][j - 1][2] + max(pr - a[i] + 1, 0));
        }
	}
	for (int i = 1; i <= (n + 1) / 2; ++i) {
        printf("%d ", min({ dp[n][i][0], dp[n][i][1], dp[n][i][2] }));
	}
	
	return 0;
}