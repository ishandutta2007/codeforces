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
        lint n, i, j; cin >> n;
        for (i = 1; 4 * i * i < n; ) ++i;
        if (4 * i * i == n) {
            cout << "YES\n";
            continue;
        }
        for (j = 1; 2 * j * j < n; ++j);
        if (2 * j * j == n) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}