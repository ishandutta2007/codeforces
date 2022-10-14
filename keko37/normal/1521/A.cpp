#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t, a, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (b == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << 1 * a << " " << (2 * b - 1) * a << " " << a * b * 2 << '\n';
        }
    }
    return 0;
}