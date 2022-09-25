#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL a, b, c;
        cin >> a >> b >> c;
        LL x = b * (max({a, b, c}) + 1) + a;
        LL y = b;
        LL z = c;
        cout << x << " " << y << " " << z << "\n";
    }
    return 0;
}