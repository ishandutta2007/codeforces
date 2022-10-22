#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 1e5 + 10;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int x = 1, y = 1, z = 1;
        for (int i = 0; i < a - c; i++) x = 10 * x + 1;
        for (int i = 0; i < b - c; i++) y = 10 * y;
        for (int i = 0; i < c - 1; i++) {
            x *= 10; y *= 10; z *= 10;
        }
        cout << x << ' ' << y << '\n';
    }
}