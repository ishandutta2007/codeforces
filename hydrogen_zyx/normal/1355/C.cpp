#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a, b, c, d;
    ll sum = 0;
    cin >> a >> b >> c >> d;
    for (int i = c; i <= d; i++) {
        if (b + c <= i) continue;
        ll c1, c2, k;
        k = b + c - i - 1;
        c1 = min(b - a, k);
        c2 = min(c - b, k);
        ll bb = k - c1;
        if (bb >= c2)
            sum += (c1 + 1) * (c2 + 1);
        else {
            sum += (k - c1 + 1) * (c1 + 1);
            sum += (c1 + k - c2+1) * (c2 - bb) / 2;
        }
    }
    cout << sum;
}