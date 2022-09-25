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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const int ox1[4] = {1, 1, 0, 0};
const int ox2[4] = {0, 0, 1, 1};
const int oy1[4] = {0, 1, 0, 1};
const int oy2[4] = {1, 0, 1, 0};

int n;

int abs1(int x) {
    return x >= 0 ? x : -x;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        bool f = 0;
        vector<int> x1(n), y1(n), x2(n), y2(n);
        for (int i = 0; i < n; i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        for (int mask = (1 << n) - 1; mask < 1 << n; mask++) {
            int mnx = inf, mxx = -inf, mny = inf, mxy = -inf;
            int s = 0;
            for (int i = 0; i < n; i++) if (mask & (1 << i)) {
                mnx = min(mnx, min(x1[i], x2[i]));
                mxx = max(mxx, max(x1[i], x2[i]));
                mny = min(mny, min(y1[i], y2[i]));
                mxy = max(mxy, max(y1[i], y2[i]));
                s += abs1(x1[i] - x2[i]) * abs1(y1[i] - y2[i]);
            }
            if (s == (mxx - mnx) * (mxy - mny) && s != 0 && (mxx - mnx) == (mxy - mny)) {
                cout << "YES\n";
                f = 1;
            }
            if (f) break;
        }
        if (!f) cout << "NO\n";
    }

    return 0;
}