#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i  =0; i< n; i++) {
        cin >> a[i];
    }
    if (a[0] != a[n - 1]) {
        cout << n - 1 << '\n';
        return 0;
    }
    int mx = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[0] != a[i])
            mx = max(mx, max(i, n - 1 - i));
    }
    cout << mx << '\n';


    return 0;
}