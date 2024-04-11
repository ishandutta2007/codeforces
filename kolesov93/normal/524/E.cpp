#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 201111;
struct cell {
    int l, r, mn;
} a[N * 4];
int pos[N];


void build(int x, int l, int r) {
    a[x].l = l; a[x].r = r;
    a[x].mn = -1e9;
    if (l != r) {
        build(x + x, l, (l + r) >> 1);
        build(x + x + 1, ((l + r) >> 1) + 1, r);
    } else {
        pos[l] = x;
    }
}

void modify(int x, int val) {
    x = pos[x];
    a[x].mn = val;
    x >>= 1;
    while (x) {
        a[x].mn = min(a[x + x].mn, a[x + x + 1].mn);
        x /= 2;
    }
}

int findmin(int x, int l, int r) {
    if (r < a[x].l || l > a[x].r) return 1e9;
    if (l <= a[x].l && a[x].r <= r) return a[x].mn;
    return min(findmin(x + x, l, r), findmin(x + x + 1, l, r));
}

bool ans[N];
pair<int, int> w[N];

struct ev {
    int pos, type, tag;

    bool operator<(const ev& A) const {
        if (pos != A.pos) return pos < A.pos;
        return type < A.type;
    }
} evs[N * 4];
int X1[N], Y1[N], X2[N], Y2[N];
int n, m, k, q;

void doit() {
    build(1, 0, max(n, m) + 1);
    int ke = 0;
    for (int i = 0; i < k; ++i) {
        evs[ke].pos = w[i].first;
        evs[ke].type = 0;
        evs[ke].tag = w[i].second;
        ke++;
    }
    for (int i = 0; i < q; ++i) {
        evs[ke].pos = X2[i];
        evs[ke].type = 1;
        evs[ke].tag = i;
        ke++;
    }
    sort(evs, evs + ke);

    for (int i = 0; i < ke; ++i) {
        if (evs[i].type == 0) {
            modify(evs[i].tag, evs[i].pos);
        } else {
            int result = findmin(1, Y1[ evs[i].tag ], Y2[ evs[i].tag ]);
            if (result >= X1[evs[i].tag]) {
                ans[evs[i].tag] = true;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%d%d", &k, &q);

    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &w[i].first, &w[i].second);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", X1+i, Y1+i, X2+i, Y2+i);
    }

    doit();
    for (int i = 0; i < k; ++i) {
        swap(w[i].first, w[i].second);
    }
    for (int i = 0; i < q; ++i) {
        swap(X1[i], Y1[i]);
        swap(X2[i], Y2[i]);
    }
    doit();

    for (int i = 0; i < q; ++i)
        if (ans[i]) puts("YES");
        else puts("NO");


    return 0;
}