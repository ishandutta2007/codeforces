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
        int x, y; cin >> x; y = 100;
        cout << y / __gcd(x, y) << '\n';

    }
}