#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>


//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


//#define int long long
#define endl "\n"

bool test(int a, int b) {
    int cnt1 = 0;
    while (a != 0) {
        cnt1 += a % 2;
        a /= 2;
    }
    while (b != 0) {
        cnt1 += b % 2;
        b /= 2;
    }
    return cnt1 % 2 == 1;
}

int dist(vector<int> &arr1, vector<int> &arr2) {
    int ans = 0;
    for (int i = 0; i < arr1.size(); i++) {
        ans += (arr1[i] != arr2[i]);
    }
    return ans;
}

vector<int> con(int mask) {
    vector<int> arr(2);
    for (int i = 0; i < 2; i++) {
        arr[i] = mask % 2;
        mask /= 2;
    }
    return arr;
}


vector<int> con1(int mask) {
    vector<int> arr(3);
    for (int i = 0; i < 3; i++) {
        arr[i] = mask % 2;
        mask /= 2;
    }
    return arr;
}

bool ll[4][4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr1(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            arr1[i][j] = c - '0';
        }
    }
    if (n >= 4 && m >= 4) {
        cout << -1;
        return 0;
    }
    vector<vector<int>> arr;
    if (n < m) {
        vector<vector<int>> arr2(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr2[j][i] = arr1[i][j];
            }
        }
        swap(n, m);
        arr = arr2;
    } else {
        arr = arr1;
    }

    vector<vector<int>> con2(8);
    for (int i = 0; i < 8; i++) {
        con2[i] = con1(i);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ll[i][j] = test(i, j);
        }
    }
    if (m == 1) {
        cout << 0;
        return 0;
    }
    if (m == 2) {
        vector<vector<int>> dp(n, vector<int>(4, 1000000000));
        for (int mask = 0; mask < 4; mask++) {
            vector<int> arr2 = con(mask);
            dp[0][mask] = dist(arr[0], arr2);
        }
        for (int i = 1; i < n; i++) {
            for (int mask1 = 0; mask1 < 4; mask1++) {
                for (int mask2 = 0; mask2 < 4; mask2++) {
                    if (test(mask1, mask2)) {
                        vector<int> arr2 = con(mask2);
                        dp[i][mask2] = min(dp[i][mask2], dp[i - 1][mask1] + dist(arr[i], arr2));
                    }
                }
            }
        }
        int ans = 1000000000;
        for (int i = 0; i  < 4; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        cout << ans;
    }
    if (m == 3) {
        vector<vector<int>> dp(n, vector<int>(8, 1000000000));
        for (int mask = 0; mask < 8; mask++) {
            vector<int> arr2 = con1(mask);
            dp[0][mask] = dist(arr[0], arr2);
        }
        for (int i = 1; i < n; i++) {
            for (int mask1 = 0; mask1 < 8; mask1++) {
                for (int mask2 = 0; mask2 < 8; mask2++) {
                    if (ll[mask1 % 4][mask2 % 4] && ll[mask1 / 2][mask2 / 2]) {
                        //vector<int> arr2 = con1(mask2);
                        dp[i][mask2] = min(dp[i][mask2], dp[i - 1][mask1] + dist(arr[i], con2[mask2]));
                    }
                }
            }
        }
        int ans = 1000000000;
        for (int i = 0; i < 8; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        cout << ans;
    }
}