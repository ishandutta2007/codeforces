#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int x : v) {
        if (upper_bound(v.begin(), v.end(), x) - v.begin() == k) {
            cout << x << '\n';
            return 0;
        }
    }
    if (k == 0 && v[0] != 1) {
        cout << 1 << '\n';
        return 0;
    }
    cout << -1 << '\n';
}