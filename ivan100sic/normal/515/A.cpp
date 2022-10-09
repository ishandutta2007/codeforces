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

    ll a, b, s;
    cin >> a >> b >> s;

    a = abs(a);
    b = abs(b);

    ll x = s - a - b;
    cout << ((x >= 0) && x % 2 == 0 ? "Yes\n"
        : "No\n");
}