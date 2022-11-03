#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        --x;
        cout << a[x % n] << b[x % m] << "\n";
    }
}