#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, a, b, c;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if ((a + b + c) % 9 == 0 && min(a, min(b, c)) >= (a + b + c) / 9) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}