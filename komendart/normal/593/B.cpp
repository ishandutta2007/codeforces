#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);

    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector< pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        int k, b;
        cin >> k >> b;
        a[i] = make_pair(k * x1 + b, k * x2 + b);
    }
    sort(a.begin(), a.end());

    for (int i = 1; i < n; i++) {
        if (a[i].second < a[i - 1].second) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
}