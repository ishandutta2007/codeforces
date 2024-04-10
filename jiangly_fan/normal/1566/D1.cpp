#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, m;
        cin >> n >> m;
        assert(n == 1);
        vector<int> v(m);
        for (int& x : v) cin >> x;
        vector<int> w = v;
        sort(w.begin(), w.end());
        vector<int> u(m);
        int ans = 0;
        for (int i = 0; i < m; i += 1) {
            int j = m - 1;
            while (w[j] != v[i] or u[j] == 1) j -= 1;
            u[j] = 1;
            for (int k = 0; k < j; k += 1) ans += u[k];
        }
        cout << ans << "\n";
    }
    return 0;
}