#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    ll a, b, c;
    cin >> a >> b >> c;
    b -= 1;
    c -= 2;
    ll o = min(a, min(b, c));
    cout << 3 * o + 3 << endl;


}