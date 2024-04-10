#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <bitset>
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
 

#define int long long
bool comp(int a, int b) {
    return (a % 2) < (b % 2);
}

int mod = 1000000007LL;

int dp[200001][10];

int solve1(int num, int m) {
    if (dp[m][num] != 0) {
        return dp[m][num];
    }
    
    if (10 - num <= m) {
        dp[m][num] =  solve1(1, m - (10 - num)) + solve1(0, m - (10 - num));
        dp[m][num] %= mod;
        return dp[m][num];
    } else {
        dp[m][num] = 1;
        return dp[m][num];
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (n != 0) {
        ans += solve1(n % 10, m);
        ans %= mod;
        n /= 10;
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();
    }
}