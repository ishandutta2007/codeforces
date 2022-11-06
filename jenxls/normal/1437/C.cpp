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

const int N = 400 + 10;
int T, n, a[N], dp[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        for (int i = 1; i <= 2 * n; i++) {
            dp[1][i] = (i < a[0]? a[0] - i : 0);
        }

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= 2 * n; j++) {
                dp[i + 1][j] = dp[i][j - 1];
                dp[i + 1][j] += abs(a[i] - j);

                if (j > i + 1)
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][j - 1]);
            }
        }

        cout << dp[n][2 * n] << '\n';
    }
}