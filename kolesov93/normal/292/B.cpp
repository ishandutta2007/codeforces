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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acos(-1.);

using namespace std;

const int N = 511111;

int n, m;
int d[N];

int w[N];

int fath(int x) {
    if (w[x] != x) w[x] = fath(w[x]);
    return w[x];
}

void un(int x, int y) {
    w[fath(x)] = fath(y);
}

int a[N + N + N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d%d", &n, &m);

    if (m > n || m < n - 1) {
        puts("unknown topology");
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        w[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        d[x]++; d[y]++;
        un(x, y);
    }

    for (int i = 2; i <= n; ++i)
        if (fath(i) != fath(1)) {
            puts("unknown topology");
            return 0;   
        }

    for (int i = 1; i <=n; ++i) a[ d[i] ]++;

    if (a[2] == n && m == n) {
        puts("ring topology");
    } else if (a[2] == n - 2 && a[1] == 2 && m == n - 1) {
        puts("bus topology");
    } else if (a[1] == n - 1 && a[n - 1] == 1 && m == n - 1) {
        puts("star topology");
    } else {
        puts("unknown topology");
    }

    return 0;
}