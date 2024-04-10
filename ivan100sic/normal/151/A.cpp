#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// 1 7 4 5 5 8 3 2

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drink = k * l;
    int lims = c * d;
    int salt = p;

    cout << min(drink/nl, min(lims, salt/np)) / n << '\n';
}