#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t, p, a, b, c;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> p >> a >> b >> c;
        llint ta = (p + a - 1) / a * a;
        llint tb = (p + b - 1) / b * b;
        llint tc = (p + c - 1) / c * c;
        cout << min(ta, min(tb, tc)) - p << '\n';
    }
    return 0;
}