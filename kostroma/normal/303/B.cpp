#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
using namespace std;
#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
int main() {
#ifdef Kostroma
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}

#define int li
int n, m, x, y, a, b;

int gcd (int q, int w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}

void solve() {
    cin >> n >> m >> x >> y >> a >> b;
    int g = gcd(a, b);
    a /= g; b /= g;
    int l = 0, r = 2000000000;
    while (l + 1 < r) {
        int mm = (l + r) / 2;
        if (mm * a > n || mm * b > m)
            r = mm;
        else
            l = mm;
    }
    int A = l * a, B = l * b;
    if (x < (A + 1) / 2)
        x = (A + 1) / 2;
    if (x + A / 2 > n)
        x = n - A / 2;
    if (y < (B + 1) / 2)
        y = (B + 1) / 2;
    if (y + B / 2 > m)
        y = m - B / 2;
    cout << x - (A + 1) / 2 << ' ' << y - (B + 1) / 2 << ' ' << x + A / 2 << ' ' << y + B / 2 << endl;
}