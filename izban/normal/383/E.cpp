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

const int maxn = 1 << 14;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
string a[maxn];
int b[1 << 24];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> n) {
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int mask = 0;
            for (int k = 0; k < 3; k++) mask |= 1 << (a[i][k] - 'a');
            b[mask]++;
        }
        for (int len = 1 << 0; len < 1 << 24; len <<= 1) {
            for (int i = 0; i < 1 << 24; i += 2 * len) {
                for (int j = 0; j < len; j++) {
                    b[i + j + len] += b[i + j];
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < 1 << 24; i++) res ^= 1LL * (n - b[i]) * (n - b[i]);
        cout << res << endl;
    }
    return 0;
}