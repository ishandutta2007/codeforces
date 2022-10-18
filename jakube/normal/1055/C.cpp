#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int la, ra, ta;
    cin >> la >> ra >> ta;
    int lb, rb, tb;
    cin >> lb >> rb >> tb;

    if (la > lb) {
        swap(la, lb);
        swap(ra, rb);
        swap(ta, tb);
    }
    ra -= la;
    lb -= la;
    rb -= la;
    la -= la;

    int da = ra - la + 1;
    int db = rb - lb + 1;

    int g = gcd(ta, tb);
    if (g == 1) {
        cout << min(da, db) << '\n';
    } else {
        int x = (lb / g) * g;
        lb -= x;
        rb -= x;
        int best = 0;
        best = max(best, min(rb, ra) + 1 - max(la, lb));
        lb -= g;
        rb -= g;
        best = max(best, min(rb, ra) + 1 - max(la, lb));
        cout << best << '\n';
    }
}