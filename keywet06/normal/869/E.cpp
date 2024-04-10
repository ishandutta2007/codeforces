#include <bits/stdc++.h>

using namespace std;

int n, m, q;

long long c[2520][2520];

map<pair<pair<int, int>, pair<int, int> >, int> g;

void R(int x, int y, long long z) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= m; j += j & -j) {
            c[i][j] += z;
        }
    }
}

long long G(int x, int y) {
    long long re = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            re += c[i][j];
        }
    }
    return re;
}

int rd() { return rand() << 15 | rand(); }

int main() {
    srand(time(0));
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; i++) {
        int o, xa, xb, ya, yb;
        scanf("%d%d%d%d%d", &o, &xa, &ya, &xb, &yb);
        if (o == 1) {
            int u = rd();
            g[make_pair(make_pair(xa, ya), make_pair(xb, yb))] = u;
            R(xa, ya, u);
            R(xa, yb + 1, -u);
            R(xb + 1, ya, -u);
            R(xb + 1, yb + 1, u);
        } else if (o == 2) {
            int u = g[make_pair(make_pair(xa, ya), make_pair(xb, yb))];
            R(xa, ya, -u);
            R(xa, yb + 1, u);
            R(xb + 1, ya, u);
            R(xb + 1, yb + 1, -u);
        } else {
            long long va = G(xa, ya);
            long long vb = G(xb, yb);
            if (va == vb) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}