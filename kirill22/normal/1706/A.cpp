#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string a(m, 'B');
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        x = min(x, m - x - 1);
        if (a[x] == 'B') {
            a[x] = 'A';
        } else {
            a[m - x - 1] = 'A';
        }
    }
    cout << a << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}