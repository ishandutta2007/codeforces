#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 111111;

int a[N];
int f[N];
int g[N];
int b[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 2; i < N; ++i)
        if (!b[i]) {
            b[i] = i;
            for (int j = i + i; j < N; j += i)
                b[j] = i;
        }

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            f[1] = 1;
        } else {
            g[i] = 1;
            int x = a[i];
            while (x != 1) {
                g[i] = max(f[ b[x] ] + 1, g[i]);
                x /= b[x];
            }

            ans = max(ans, g[i]);

            x = a[i];
            while (x != 1) {
                f[ b[x] ] = max(f[ b[x] ], g[i]);
                x /= b[x];
            }
        }
    }

    cout << ans << endl;

    return 0;
}