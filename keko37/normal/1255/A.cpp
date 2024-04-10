#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int a, b, d;
        cin >> a >> b;
        d = abs(a - b);
        cout << d / 5 + d % 5 / 2 + d % 5 % 2 << '\n';
    }
    return 0;
}