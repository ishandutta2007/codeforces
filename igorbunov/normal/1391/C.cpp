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


#define int long long
#define endl "\n"

int dp[1000007];
int f[1000007];

int inf = 1000000007LL;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    f[0] = 1LL;
    for (int i = 1; i <= 1000000; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= inf;
    }
    dp[3] = 2;
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = f[i] - 2 * (f[i - 1] - dp[i - 1]);
        dp[i] += inf * 100;
        dp[i] %= inf;
    }
    cout << dp[n];
}