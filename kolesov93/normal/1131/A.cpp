#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    ll w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;

    ll ans = 2LL * (w1 + h1 + h2);
    ans += 4;


    cout << ans << endl;


    return 0;
}