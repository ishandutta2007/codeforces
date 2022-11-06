#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);

    int x;
    cin >> x;

    vector< pair<int, int> > result;
    int pref = 0;
    for (int n = 1; ; n++) {
        int A = n * (n + 1) / 2;
        int B = x - pref + n * n * (n - 1) / 2;
        int m = B / A;
        if (m < n) break;
        if (A * m == B) {
            result.push_back({n, m});
            if (n != m) result.push_back({m, n});
        }
        pref += n * n;
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (auto i: result) {
        cout << i.first << ' ' << i.second << '\n';
    }
}