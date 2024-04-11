#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>
#include <memory>
#include <iomanip>

typedef long long ll;
typedef long double ld;

using namespace std;

const int MX = 5000 + 7;

int dp[MX][MX];

void up(int& a, int b) {
    a = max(a, b);
}

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                up(dp[i + 1][j + 1], dp[i][j] + 2);
            }
            up(dp[i + 1][j], dp[i][j] - 1);
            up(dp[i][j + 1], dp[i][j] - 1);
        }
    }
    int mx = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << '\n';


    return 0;
}