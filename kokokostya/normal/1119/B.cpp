#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;

        vector<int> b = a;
        sort(b.begin(), b.begin() + m);
        long long cur = h;
        for (int i = m - 1; i >= 0; i -= 2) {
            cur -= b[i];
        }
        if (cur >= 0)
            l = m;
        else
            r = m;

    }

    cout << l << '\n';


    return 0;
}