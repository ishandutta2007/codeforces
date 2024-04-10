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

const int maxn = 53;
const int maxm = 10010;
const ll inf = 1000000000000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, d;
int a[maxn];
ll dp[maxn * maxm];
// dp1[maxn] --      i

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n >> d) {
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        
        for (int i = 0; i < maxn * maxm; i++) dp[i] = 0;
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = maxn * maxm - 1 - a[i]; j >= 0; j--) if (dp[j]) {
                dp[j + a[i]] = 1;
            }
        }
        
        int cur = 0;
        int it = 0;
        while (1) {
            int ncur = 0;
            for (int i = cur + 1; i <= cur + d; i++) {
                if (dp[i]) {    
                    ncur = i;
                }
            }
            if (ncur == 0) break;
            it++;
            cur = ncur;
        }
        cout << cur << " " << it << endl;
        
        /*for (int i = 0; i < n; i++) {
            ll best = inf;
            for (int j = max(0, a[i] - d); j < maxn * maxm; j++) best = min(best, dp[j]);
            if (best == inf) break;
            best++;
            for (int j = maxn * maxm - 1 - a[i]; j >= 0; j--) {
                dp[j + a[i]] = min(dp[j + a[i]], dp[j] + best);
            }
        }
        
        for (int i  = maxn * maxm - 1; i >= 0; i--) {
            if (dp[i] != inf) {
                cout << i << " " << dp[i] << endl;
                break;
            }
        }*/
    }

	return 0;
}