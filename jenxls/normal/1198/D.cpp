#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 50 + 2;
int n, dp[N][N][N][N];
string s[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> s[i];

    for (int x1 = n - 1; x1 >= 0; x1--) {
        for (int x2 = x1 + 1; x2 <= n; x2++) {
            for (int y1 = n - 1; y1 >= 0; y1--) {
                for (int y2 = y1 + 1; y2 <= n; y2++) {
                    if (x2 - x1 == 1 && y2 - y1 == 1) {
                        dp[x1][y1][x2][y2] = (s[x1][y1] == '#');
                        continue;
                    }

                    dp[x1][y1][x2][y2] = max(x2 - x1, y2 - y1);

                    for (int mx = x1 + 1; mx < x2; mx++)
                        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dp[x1][y1][mx][y2] + dp[mx][y1][x2][y2]);

                    for (int my = y1 + 1; my < y2; my++)
                        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dp[x1][y1][x2][my] + dp[x1][my][x2][y2]);
                }
            }
        }
    }

    cout << dp[0][0][n][n] << '\n';
}