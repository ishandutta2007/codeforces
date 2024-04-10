#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int g = __gcd(x, y);
    x /= g;
    y /= g;
    int k = min(a / x, b / y);
    cout << x * k << " " << y * k;
}