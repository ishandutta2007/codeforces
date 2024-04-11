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

const int N = 1000111;

struct cell {
    int l, r;
    int val;
    bool cool;
} a[N + N + N];

void build(int x, int l, int r) {
    a[x].l = l;
    a[x].r = r;
    a[x].val = -1;
    a[x].cool = true;

    if (l != r) {
        build(x + x, l, (l + r) >> 1);
        build(x + x + 1, ((l + r) >> 1) + 1, r);
    }
}

void modify(int x, int l, int r, int val) {
    if (a[x].l > r || a[x].r < l) return;
    if (l <= a[x].l && r >= a[x].r) {
        a[x].val = val;
        a[x].cool = true;
        return;
    }
    if (a[x].cool) {
        a[x].cool = false;
        a[x + x].cool = a[x + x + 1].cool = true;
        a[x + x].val = a[x + x + 1].val = a[x].val;
    }

    modify(x + x, l, r, val);
    modify(x + x + 1, l, r, val);
}

int findans(int x, int pos) {
    if (a[x].cool) return a[x].val;
    if (a[x + x].r >= pos) return findans(x + x, pos);
    return findans(x + x + 1, pos);
}

int A[N], B[N];

int reqx[N], reqy[N], reqk[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", A + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", B + i);
    }

    build(1, 1, n);

    for (int i = 1; i <= m; ++i) {
        int t; scanf("%d", &t);

        if (t == 1) {
            scanf("%d%d%d", reqx + i, reqy + i, reqk + i);
            modify(1, reqy[i], reqy[i] + reqk[i] - 1, i);            
        } else {
            int pos; scanf("%d", &pos);
            int cans = findans(1, pos);
            if (cans == -1) {
                printf("%d\n", B[pos - 1]);
            } else {
                pos = pos - reqy[cans] + reqx[cans];
                printf("%d\n", A[pos - 1]);
            }
        }
    }

    return 0;
}