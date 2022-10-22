#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll m, n;
        cin >> n >> m;
        cout << -m + (m * m + m) / 2 + m * (n * n + n) / 2 << '\n';
    }
}