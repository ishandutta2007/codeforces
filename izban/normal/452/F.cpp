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

const int maxn = 300200;
const int inf = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;

const int q[2] = {239, 997};
const int mod[2] = {1e9 + 7, 1e9 + 9};
int p[maxn][2];
int t1[4 * maxn][2], t2[4 * maxn][2];

void upd(int t[4 * maxn][2], int v, int tl, int tr, int x) {
    if (tl == tr) {
        for (int k = 0; k < 2; k++) {
            t[v][k] = p[tl][k];
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    if (x <= tm) upd(t, v * 2, tl, tm, x);
    else upd(t, v * 2 + 1, tm + 1, tr, x);
    for (int k = 0; k < 2; k++) {
        t[v][k] = (t[v * 2][k] + 1LL * t[v * 2 + 1][k] * p[tm - tl + 1][k]) % mod[k];
    }
}

pair<int, int> get(int t[4 * maxn][2], int v, int tl, int tr, int l, int r) {
    if (l > r) return make_pair(0, 0);
    if (l == tl && r == tr) return make_pair(t[v][0], t[v][1]);
    int tm = (tl + tr) >> 1;
    pair<int, int> o1 = get(t, v * 2, tl, tm, l, min(r, tm));
    pair<int, int> o2 = get(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    pair<int, int> res = o1;
    res.first = (res.first + 1LL * o2.first * p[max(0, tm - l + 1)][0]) % mod[0];
    res.second = (res.second + 1LL * o2.second * p[max(0, tm - l + 1)][1]) % mod[1];
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    for (int k = 0; k < 2; k++) {
        p[0][k] = 1;
        for (int i = 1; i < maxn; i++) {
            p[i][k] = 1LL * p[i - 1][k] * q[k] % mod[k];
        }
    }
    
    while (cin >> n) {
        memset(t1, 0, sizeof(t1));
        memset(t2, 0, sizeof(t2));
        bool ok = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x--;
            upd(t1, 1, 0, n - 1, x);
            upd(t2, 1, 0, n - 1, n - 1 - x);             
            if (x == 0 || x == n - 1) {;             
                continue;
            }
            int l = max(0, x - (n - 1 - x));
            int r = min(n - 1, 2 * x);
            pair<int, int> o1 = get(t1, 1, 0, n - 1, l, r);
            pair<int, int> o2 = get(t2, 1, 0, n - 1, n - r - 1, n - l - 1);
            o1.first = 1LL * o1.first * p[maxn - l - 1][0] % mod[0];
            o1.second = 1LL * o1.second * p[maxn - l - 1][1] % mod[1];
            o2.first = 1LL * o2.first * p[maxn - (n - r - 1) - 1][0] % mod[0];
            o2.second = 1LL * o2.second * p[maxn - (n - r - 1) - 1][1] % mod[1];        
            ok |= o1 != o2;       
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    
    return 0;
}