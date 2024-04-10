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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;
int a[maxn];
ll sum[maxn], sq[maxn];

inline ll sqr(ll x) {
    return x * x;
}

ll slowsolve() {
    for (int i = 1; i <= n; i++) sum[i] = (i ? sum[i - 1] : 0) + a[i];
    for (int i = 0; i <= n; i++) sq[i] = 1LL * i * i;
    
    ll res = 8e18;
    for (int i = 2; i <= n; i++) res = min(res, 1 + 1LL * a[i] * a[i]);
    /*for (int i = 1; i <= n; i++) {
        ll csum = 0;
        int to = min(n, i + (int)sqrt(res) + 10);
        for (int j = i + 1; j <= to; j++) {
            csum += a[j];
            res = min(res, csum * csum + sq[j - i]);
        }
    }*/
    for (int len = 1; len * len < res; len++) {
        if (clock() > 1800) return res;
        int to = n - len;
        for (int i = 2; i <= to; i++) {
            res = min(res, sqr(sum[i + len] - sum[i - 1]) + sq[len + 1]);
        }
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    //while (cin >> n) {
        //n = 1e5;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        cout << slowsolve() << endl;
    //}
 ;
    return 0;
}