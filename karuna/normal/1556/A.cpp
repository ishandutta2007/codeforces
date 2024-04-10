#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if ((a + b) % 2 == 1) {
            cout << -1 << '\n';
        }
        else {
            if (a == b && b == 0) cout << 0 << '\n';
            else if (a == b) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }
}