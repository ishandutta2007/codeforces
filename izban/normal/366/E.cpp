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
#define y1 _dfdfdfd


const int maxn = 1 << 11;
const int maxm = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int a[maxn][maxn];
int b[maxm], c[10][10];
int l[10][maxn], r[10][maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, k, s;
    while (cin >> n >> m >> k >> s) {
        memset(c, 0, sizeof(c));
        memset(l, -1, sizeof(l));
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
        for (int i = 0; i < s; i++) {
            scanf("%d", &b[i]);
            if (i) c[b[i - 1]][b[i]] = 1, c[b[i]][b[i - 1]] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) r[a[i][j]][i] = j;
            for (int j = m - 1; j >= 0; j--) l[a[i][j]][i] = j;
        }
        
        int ans = 0;
        for (int o1 = 1; o1 <= k; o1++) {
            for (int o2 = 1; o2 <= k; o2++) if (c[o1][o2]) {
                for (int i = 0; i < n; i++) if (l[o1][i] != -1) {
                    for (int j = 0; j < n; j++) if (l[o2][j] != -1) {
                        if (o1 == 3 && o2 == 1 && i == 3 && j == 0) 
                            ans = ans;
                        ans = max(ans, abs(i - j) + max(abs(l[o1][i] - r[o2][j]), abs(r[o1][i] - l[o2][j])));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}