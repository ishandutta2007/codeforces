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

const int maxn = 2020;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

vector<int> e[maxn];
int dp[maxn][maxn];

void precalc() {
    for (int i = 1; i <= 2000; i++) {
        for (int j = i; j <= 2000; j += i) {
            e[j].push_back(i);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    precalc();
    
    int n, k;
    while (cin >> n >> k) {
        for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) dp[j][i] = 0;
        dp[0][1] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                for (int l = 0; l < e[j].size(); l++) {
                    dp[i][j] = dp[i][j] + dp[i - 1][e[j][l]];
                    if (dp[i][j] >= mod) dp[i][j] -= mod;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += dp[k][i];
            if (ans >= mod) ans -= mod;
        }
        cout << ans << endl;
    }

	return 0;
}