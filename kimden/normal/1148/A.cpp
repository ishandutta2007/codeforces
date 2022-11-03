#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;



int main() {
    ios_base::sync_with_stdio(false);
    ll a, b, c;
    cin >> a >> b >> c;
    c *= 2;
    if (b > a + 1) {
        b = a + 1;
    }
    if (a > b + 1) {
        a = b + 1;
    }
    c += a + b;
    cout << c << endl;

}