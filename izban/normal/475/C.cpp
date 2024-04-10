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

const int maxn = 1111;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
string a[maxn];
int sum[maxn][maxn];
int all, ans, sx, sy;

int getSum(int u, int l, int d, int r) {
    int ans = 0;
    ans += sum[d][r];
    if (l) ans -= sum[d][l - 1];
    if (u) ans -= sum[u - 1][r];
    if (l && u) ans += sum[u - 1][l - 1];
    return ans;
}

void start(int w, int h) {
    int cx = sx, cy = sy;
    bool ok = 1;
    int curSum = getSum(cx, cy, cx + h - 1, cy + w - 1);
    if (curSum != w * h) return;
    
    while (1) {
        bool f1 = cx + h < n && a[cx + h][cy] == 'X';
        bool f2 = cy + w < m && a[cx][cy + w] == 'X';
        if (f1 && f2) {
            ok = 0;
            break;
        }
        if (!f1 && !f2) break;
        if (f1) {
            ok &= getSum(cx + h, cy, cx + h, cy + w - 1) == w;
            curSum += w;
            cx++;
        }
        if (f2) {
            ok &= getSum(cx, cy + w, cx + h - 1, cy + w) == h;
            curSum += h;
            cy++;
        }
    }
    ok &= curSum == all;
    if (ok) ans = min(ans, w * h);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) cin >> a[i];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[i][j] = (a[i][j] == 'X') + (i ? sum[i - 1][j] : 0) + (j ? sum[i][j - 1] : 0) - (i && j ? sum[i - 1][j - 1] : 0);
            }
        }
        
        sx = -1, sy = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m && sx == -1 && sy == -1; j++) {
                if (a[i][j] == 'X') {
                    sx = i;
                    sy = j;
                }
            }
        }
        
        all = sum[n - 1][m - 1];
        ans = n * m + 1;
        {
            int w = 0;
            while (sy + w < m && a[sx][sy + w] == 'X') w++;
            for (int h = 1; sx + h <= n; h++) {
                start(w, h);
            }
        }
        {
            int h = 0;
            while (sx + h < n && a[sx + h][sy] == 'X') h++;
            for (int w = 1; sy + w <= m; w++) {
                start(w, h);
            }
        }
        if (ans == n * m + 1) ans = -1;
        cout << ans << endl;
    }
    
    return 0;
}