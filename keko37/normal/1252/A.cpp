#include<bits/stdc++.h>

using namespace std;

int t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1) cout << "Finite\n"; else cout << "Infinite\n";
    }
    return 0;
}