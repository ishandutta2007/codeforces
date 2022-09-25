#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
int s[maxn];
int dp[21][1 << 20];
char c[maxn];
int t[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> s[i];
        cin >> m;
        for (int i = 0; i < m; i++) cin >> c[i] >> t[i];
        /*n = 100;
        for (int i = 0; i < n; i++) s[i] = rand() % (1000000) + 1;
        m = 20;
        for (int i = 0; i < m; i++) c[i] = (i == 5 || i == 14 ? 'p' : 'b'), t[i] = (i % 2) + 1;*/
        
        sort(s, s + n);
        reverse(s, s + n);
        reverse(s, s + min(n, m));
        n = min(n, m);
        
        for (int i = 0; i <= n; i++) for (int j = 0; j < 1 << n; j++) dp[i][j] = inf;
        for (int j = 0; j < 1 << n; j++) dp[n][j] = 0;
        
        for (int k = n - 1; k >= 0; k--) {
            int limit = k ? 0 : ((1 << n) - 1);
            for (int mask = limit; mask < (1 << n); mask++) {
                int o = c[k] == 'p';
                if (t[k] == 1) {
                    dp[k][mask] = -1e9;
                    for (int i = 0; i < n; i++) {
                        if (mask & (1 << i)) {
                            dp[k][mask] = max(dp[k][mask], dp[k + 1][mask ^ (1 << i)] + s[i] * o);
                        }
                    }
                    if (c[k] == 'b') dp[k][mask] = max(dp[k][mask], dp[k + 1][mask]);
                } else {
                    dp[k][mask] = 1e9;
                    for (int i = 0; i < n; i++) {
                        if (mask & (1 << i)) {
                            dp[k][mask] = min(dp[k][mask], dp[k + 1][mask ^ (1 << i)] - s[i] * o);
                        }
                    }
                    if (c[k] == 'b') dp[k][mask] = min(dp[k][mask], dp[k + 1][mask]);  
                }
            }
        }
        cout << dp[0][(1 << n) - 1] << endl;
    }
    
	return 0;
}