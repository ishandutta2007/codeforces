#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[v[v[i]-1]-1]-1 == i) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
}