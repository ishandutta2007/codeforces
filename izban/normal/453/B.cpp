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

const int maxn = 101;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;
int a[maxn];
int dp[maxn][1 << 10][100];
int p[maxn][1 << 10][100];
vector<int> pr;
int cmask[100];
bool IsPr[10000];

bool ispr(int x) {
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
    IsPr[x] = 1;
    return 1;
}

void getmask(int x) {
    int X = x;
    for (int i = 0; i < 10; i++) {
        if (x % pr[i] == 0) {
            while (x % pr[i] == 0) x /= pr[i];
            cmask[X] |= 1 << i;
        }
    }
    if (x > 1) cmask[X] = -1;
}

void rec(int n, int mask, int j) {
    if (n == 0) return;
    int nmask, nj;
    if (p[n][mask][j] == 1) {
        nmask = mask;
        nj = j;
    } else if (p[n][mask][j] > 30 && IsPr[p[n][mask][j]]) {
        nmask = mask;
        nj = j - 1;
    } else {
        nmask = mask ^ cmask[p[n][mask][j]];
        nj = j;
    }
    rec(n - 1, nmask, nj);
    cout << p[n][mask][j] << " ";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    for (int i = 2; pr.size() < 150; i++) if (ispr(i)) pr.push_back(i);
    
    for (int i = 2; i <= 60; i++) getmask(i);
    
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        
        memset(dp, 127, sizeof(dp));
        dp[0][0][0] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < 1 << 10; mask++) {
                for (int j = 0; j < 100; j++) if (dp[i][mask][j] < 2e9) {
                    if (dp[i + 1][mask][j] > dp[i][mask][j] + abs(a[i] - 1)) {
                        dp[i + 1][mask][j] = dp[i][mask][j] + abs(a[i] - 1);
                        p[i + 1][mask][j] = 1;
                    }
                    if (dp[i + 1][mask][j + 1] > dp[i][mask][j] + abs(a[i] - pr[10 + j])) {
                        dp[i + 1][mask][j + 1] = dp[i][mask][j] + abs(a[i] - pr[10 + j]);
                        p[i + 1][mask][j + 1] = pr[10 + j];
                    }
                    for (int k = 2; k <= 60; k++) {
                        if (cmask[k] != -1 && (cmask[k] & mask) == 0) {
                            if (dp[i + 1][mask | cmask[k]][j] > dp[i][mask][j] + abs(a[i] - k)) {
                                dp[i + 1][mask | cmask[k]][j] = dp[i][mask][j] + abs(a[i] - k);
                                p[i + 1][mask | cmask[k]][j] = k;
                            }
                        }
                    }
                }
            }
        }
        
        int ans = 1e9;
        int ansm = -1, ansj = -1;
        for (int mask = 0; mask < 1 << 10; mask++) for (int j = 0; j < 100; j++) {
            if (ans > dp[n][mask][j]) {
                ans = dp[n][mask][j];
                ansm = mask;
                ansj = j;
            }
        }
        rec(n, ansm, ansj);
        cout << endl;
        /*int ans = 1e9;
        int ansi = -1, ansm = -1;
        
        for (int i = 0; i < n; i++) precalc[i] = calc(i);
        
        memset(dp, 127, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < 1 << 10; mask++) {
                if (ans > dp[i][mask] + precalc[i]) {
                    ans = dp[i][mask] + precalc[i];
                    ansi = i;
                    ansm = mask;
                }
                for (int )
            }
        }
        rec()*/
    }
    
    return 0;
}