#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    
    vector<int> h;
    vector<bool> b(n + 1, false);
    vector<int> indices(n+1);

    for (int i = 0; i < n; i++) {
        if (!b[f[i]]) {
            h.push_back(f[i]);
            b[f[i]] = true;
            indices[f[i]] = h.size();
        }
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] && f[i-1] != i) {
            cout << -1 << endl;
            return 0;
        }
    }

    int m = h.size();
    vector<int> g(n, 0);
    for (int i = 1; i <= m; i++) {
        // g[h[i]] == i
        g[h[i-1]-1] = i;
    }

    for (int  i = 1; i <= n; i++) {
        // h[g[i]] == f[i]
        g[i-1] = indices[f[i-1]];
    }

    cout << m << endl;
    for (int i : g) {
        cout << i << ' ';
    }
    cout << endl;
    for (int i : h) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}