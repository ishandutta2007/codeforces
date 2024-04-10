#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t, a, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if ((a + b) % 3 == 0 && min(a, b) >= (a + b) / 3) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}