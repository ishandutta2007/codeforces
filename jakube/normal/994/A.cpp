#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<bool> b(10);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[x] = true;
    }
    
    for (int x : v) {
        if (b[x])
            cout << x << ' ';
    }
    cout << endl;
}