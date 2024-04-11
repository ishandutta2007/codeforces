#include <iostream>
#include <memory.h>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 100111;
struct cell {
    int son;
    int version;
    int add, mx;

    explicit cell(int av = 0, int ason = -1, int aadd = 0, int amx = 0)  {
        version = av;
        son = ason;
        add = aadd; mx = amx;
    }
};
vector<cell> a;
int version = 0;
int roots[N];
int n;

void inctime() {
    ++version;
    if (version == 1) {
        a.push_back(cell());
    } else {
        a.push_back(a[roots[version - 1]]);
        a.back().version = version;
    }

    roots[version] = int(a.size()) - 1;
}

void ensure(int x) {
    if (a[x].son == -1) {
        a[x].son = a.size();
        a.push_back(cell(a[x].version));
        a.push_back(cell(a[x].version));
    } else if (a[ a[x].version ].version != a[x].version){
        a.push_back(a[ a[x].son ]);
        a.back().version = a[x].version;
        a.push_back(a[ a[x].son + 1 ]);
        a.back().version = a[x].version;
        a[x].son = int(a.size()) - 2;
    }
}

void modify(int x, int lb, int rb, int l, int r, int add) {
    if (rb < l || lb > r) return;
    if (l <= lb && rb <= r) {
        a[x].add += add;
        return;
    }

    ensure(x);
    modify(a[x].son, lb, (lb + rb) >> 1, l, r, add);
    modify(a[x].son + 1, ((lb + rb) >> 1) + 1, rb, l, r, add);
    a[x].mx = max(a[ a[x].son ].mx + a[ a[x].son ].add, a[ a[x].son + 1 ].mx + a[ a[x].son + 1 ].add);
}

int findmax(int x, int lb, int rb, int l, int r, int sumadd) {
    if (rb < l || lb > r) return 0;
    if (l <= lb && rb <= r) {
        return a[x].mx + sumadd + a[x].add;
    }
    sumadd += a[x].add;

    int ans = 0;
    if (a[x].son != -1) {
        ans = findmax(a[x].son, lb, (lb + rb) >> 1, l, r, sumadd);
        ans = max(ans, findmax(a[x].son + 1, ((lb + rb) >> 1) + 1, rb, l, r, sumadd));
    } else {
        if (l <= ((lb + rb) >> 1)) ans = sumadd;
        if (r > ((lb + rb) >> 1)) ans = max(ans, sumadd);
    }

    return ans;
}

int h[N];

int dsu[N], sz[N], lab[N];

int fath(int x) {
    if (dsu[x] != x) {
        dsu[x] = fath(dsu[x]);
    }
    return dsu[x];
}

void un(int x, int y) {
    x = fath(x); y = fath(y);
    if (x == y) return;
    dsu[x] = y;
    sz[y] += sz[x];
}

int who[N];

int main() {
    scanf("%d", &n);
    inctime();
    vector< pair<int, int> > heights;
    for (int i = 0; i < n; ++i) {
        scanf("%d", h + i);
        heights.push_back(make_pair(h[i], i));
    }
    sort(heights.begin(), heights.end());
    reverse(heights.begin(), heights.end());
    memset(lab, -1, sizeof(lab));

    for (int i = 0; i < n; ++i) {
        int pos = heights[i].second;
        lab[pos] = i + 1;
        dsu[i + 1] = i + 1;
        sz[ lab[pos] ] = 1;

        if (pos + 1 < n && lab[pos + 1] != -1) {
            un(lab[pos], lab[pos + 1]);
        }
        modify(roots[version], 0, n - 1, pos, pos, sz[ fath(lab[pos]) ]);
        if (pos >= 0 && lab[pos - 1] != -1) {
            int was = sz[fath(lab[pos - 1])];
            modify(roots[version], 0, n - 1, pos - was, pos - 1, sz[ fath(lab[pos]) ]);
            un(lab[pos - 1], lab[pos]);
        }
        who[pos] = version;

        inctime();
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r, w;
        scanf("%d%d%d", &l, &r, &w);

        --l; --r;

        int L = 1, R = n;
        int lb = l, rb = r - w + 1;
        while (L < R) {
            int center = (L + R) >> 1;

            if (findmax(roots[center], 0, n - 1, lb, rb, 0) >= w) R = center;
            else L = center + 1;
        }

        printf("%d\n", heights[L - 1].first);
    }

    return 0;
}