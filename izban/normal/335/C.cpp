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
const string ans[2] = {"WIN", "LOSE"};
int n, r;
bool bad[maxn][2];

int gr[maxn][maxn][16];

int mex(vector<int> v) {
    sort(v.begin(), v.end());
    int cur = 0;
    for (int ans = 0; ans < inf; ans++) {
        if (cur < v.size() && v[cur] == ans)
            while (cur < v.size() && v[cur] == ans)
                cur++;
        else return ans;
    }
}

int getgr(int l, int r, int mask) {
    if (gr[l][r][mask] != -1) return gr[l][r][mask];

    if (mask & 1) bad[l][0] = 1;
    if (mask & 2) bad[l][1] = 1;
    if (mask & 4) bad[r][0] = 1;
    if (mask & 8) bad[r][1] = 1;

    vector<int> v;
    for (int i = l; i <= r; i++) {
        for (int x = 0; x < 2; x++) if (!bad[i][x]) {
            int cr = 0;
            if (i > l) {
                int nmask = mask & 3;
                if (!bad[i - 1][1 - x]) nmask |= 1 << (2 + 1 - x);
                cr ^= getgr(l, i - 1, nmask);
            }
            if (i < r) {
                int nmask = mask & 12;
                if (!bad[i + 1][1 - x]) nmask |= 1 << (1 - x);
                cr ^= getgr(i + 1, r, nmask);
            }
            v.push_back(cr);
        }
    }
    gr[l][r][mask] = mex(v);

    if (mask & 1) bad[l][0] = 0;
    if (mask & 2) bad[l][1] = 0;
    if (mask & 4) bad[r][0] = 0;
    if (mask & 8) bad[r][1] = 0;
    return gr[l][r][mask];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    while (cin >> r >> n) {
        memset(bad, 0, sizeof(bad));
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            bad[x][y] = 1;
            if (x > 0) bad[x - 1][1 - y] = 1;
            bad[x][1 - y] = 1;
            if (x < r - 1) bad[x + 1][1 - y] = 1;
        }
        memset(gr, -1, sizeof(gr));
        cout << ans[!getgr(0, r - 1, 0)] << endl;
    }

    return 0;
}