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

const int inf = 2e8 + 1;
int a, m, n;
int rain[2001];
int umb[2001];
int dp[2001][2001];
vector<int> comp;

int find(int x) {
    return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> m >> n;
	for (int i = 0; i < a; ++i) {
        umb[i] = inf;
	}
	int l, r;
	for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        for (int j = l; j < r; ++j) rain[j] = 1;
	}
	for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        umb[l] = min(umb[l], r);
        comp.push_back(r);
	}
	comp.push_back(0);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	n = comp.size();
	for (int i = 0; i < a; ++i) {
        umb[i] = find(umb[i]);
	}
	for (int i = 1; i < n; ++i) {
        if (i != umb[0]) dp[0][i] = inf;
	}
	for (int i = 1; i <= a; ++i) {
        int mn = (rain[i - 1] ? inf : dp[i - 1][0]);
        for (int j = 1; j < n; ++j) {
            mn = min(mn, dp[i][j] = dp[i - 1][j] + comp[j]);
            dp[i][j] = min(dp[i][j], inf);
        }
        dp[i][0] = mn;
        if (umb[i] < n) dp[i][umb[i]] = mn;
	}
	printf("%d\n", dp[a][0] < inf ? dp[a][0] : -1);
	return 0;
}