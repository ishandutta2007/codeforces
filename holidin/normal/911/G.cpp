#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 1;
const int MX = 100;

int d[N][MX];
int v, a[N];

void push(int v) {
    for (int i = 0; i < MX; ++i) {
        d[2*v + 1][i] = d[v][d[2*v + 1][i]];
        d[2*v + 2][i] = d[v][d[2*v + 2][i]];
    }
    for (int i = 0; i < MX; ++i)
        d[v][i] = i;
}



void mov(int v, int vl, int vr, int l, int r, int x, int y) {
    if (l <= vl && vr <= r) {
        for (int i = 0; i < MX; ++i)
        if (d[v][i] == x)
            d[v][i] = y;
    } else if (l >= vr || vl >= r)
            return;
        else {
            push(v);
            mov(2*v + 1, vl, (vl + vr) / 2, l, r, x, y);
            mov(2*v + 2, (vl + vr) / 2, vr, l, r, x, y);
        }
}
int main() {
    int i, j, k, n, l, r, x, y, q;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    v = 1;
    while (v < n) v *= 2;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        --a[i];
        for (j = 0; j < MX; ++j)
            d[i + v - 2][j] = j;
    }
    for (i = v - 2; i >= 0; --i)
    for (j = 0; j < MX; ++j)
        d[i][j] = j;
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> l >> r >> x >> y;
        --x;
        --y;
        mov(0, 1, v + 1, l, r + 1, x, y);
    }
    for (i = 0; i < v - 1; ++i)
        push(i);
    for (i = 1; i <= n; ++i) {
        cout << d[i + v - 2][a[i]] + 1 << ' ';
    }
}