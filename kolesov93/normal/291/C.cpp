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

typedef unsigned long long ull;

const int N = 100111;

ull a[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x[4];
        scanf("%d.%d.%d.%d", x, x+1, x+2, x+3);

        ull y = 0;
        for (int j = 0; j < 4; ++j) {
            y = (y << 8) + (x[j] & ((1 << 8) - 1)); 
        }

        a[i] = y;
    }

    ull curmask = 0;
    for (int j = 31; j >= 0; --j) {
        curmask |= (1 << j);

        set<ull> masks;
        for (int i = 0; i < n; ++i) {
            masks.insert(a[i] & curmask);
        }

        if (masks.size() == k) {
            vector<int> res;
            for (int q = 0; q < 4; ++q) {
                res.push_back(curmask & ((1 << 8) - 1));
                curmask >>= 8;
            }
            for (int q = 3; q >= 0; --q) {
                printf("%d", res[q]);
                if (q != 0) putchar('.');
            }
            cout << endl;
            return 0;
        }
    }

    puts("-1");

    return 0;
}