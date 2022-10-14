#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint la, ra, ta;
llint lb, rb, tb;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    llint g = __gcd(ta, tb);
    llint lena = ra - la + 1;
    llint lenb = rb - lb + 1;
    la %= g; lb %= g;
    ra = la + lena - 1;
    rb = lb + lenb - 1;
    llint sol = 0;
    sol = max(sol, min(ra, rb) - max(la, lb) + 1);
    if (la < lb) {
        la += g; ra += g;
    } else {
        lb += g; rb += g;
    }
    sol = max(sol, min(ra, rb) - max(la, lb) + 1);
    cout << sol;
    return 0;
}