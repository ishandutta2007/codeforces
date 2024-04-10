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
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200200;
const int maxm = 600;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, k;
double dp[maxm];
double p[2][maxm];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (cin >> n >> k) {
        for (int j = 0; j < maxm; j++) {
            //dp[0][j] = dp[1][j] = 0;
            dp[j] = 0;
            p[0][j] = p[1][j] = 0;
        }
        p[0][1] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = maxm - 2; j > 0; j--) {
                if (p[0][j] < 1e-20) continue;
                dp[j] += ((j + 1) / 2.0) * (j / (j + 1.0)) / k * p[0][j];
                p[1][j] += (1 - 1.0 / (j + 1.0) / k) * p[0][j];
                dp[j + 1] += j * (1 / (j + 1.0)) / k * p[0][j];
                p[1][j + 1] += 1.0 / (j + 1.0) / k * p[0][j];
            }
            for (int j = 1; j < maxm; j++) {
                //dp[0][j] = dp[1][j];
                p[0][j] = p[1][j];
                p[1][j] = 0;
            }
        }
        double sum = 0;
        for (int j = 1; j < maxm; j++) sum += dp[j];
        printf("%.15lf\n", k * sum);
    }
    
    return 0;
}