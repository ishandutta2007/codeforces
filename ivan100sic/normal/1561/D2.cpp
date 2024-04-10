// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
int a[4000005], z[4000005];

int ad(int x, int y) {
    x += y;
    if (x >= m) x -= m;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0) x += m;
    return x;
}

void walk_up(int x) {
    for (int q=1; q*x<=n; q++) {
        z[q*x] = ad(z[q*x], a[x]);
        if (q*x+q <= n) {
            z[q*x+q] = sub(z[q*x+q], a[x]);
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    a[1] = 1;
    int s = 1;
    walk_up(1);
    for (int x=2; x<=n; x++) {
        a[x] = s;
        z[x] = ad(z[x], z[x-1]);
        a[x] = ad(a[x], z[x]);
        s = ad(s, a[x]);
        walk_up(x);
    }

    cout << a[n] << '\n';
}