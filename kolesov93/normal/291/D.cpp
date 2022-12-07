#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

using namespace std;

const int N = 10111;

int a[N], b[N], c[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        a[i] = 1;
    }
    a[n] = 0;

    while (k--) {
        for (int i = n; i; --i) {
            int need = n - i;

            int l = 1, r = n;
            while (l < r) {
                int center = (l + r) >> 1;
                if (a[i] + a[center] <= need) r = center;
                else l = center + 1;
            }
            c[i] = l;
        }

        for (int i = 1; i <= n; ++i) printf("%d ", c[i]);
        puts("");

        for (int i = 1; i <= n; ++i) {
            b[i] = a[i] + a[ c[i] ];
        }
        for (int i = 1; i <= n; ++i) {
            a[i] = b[i];
        }
    }

    return 0;
}