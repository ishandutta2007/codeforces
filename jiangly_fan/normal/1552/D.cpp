#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> v(n);
        for (LL& x : v) cin >> x;
        int ans = 0;
        for (int i = 1; i < (1 << n); i += 1) {
            vector<int> w;
            for (int j = 0; j < n; j += 1) if ((i >> j) & 1) w.push_back(v[j]);
            int nn = w.size();
            for (int ii = 0; ii < (1 << nn); ii += 1) {
                LL sum = 0;
                for (int jj = 0; jj < nn; jj += 1) {
                    if ((ii >> jj) & 1) sum += w[jj];
                    else sum -= w[jj];
                }
                if (sum == 0) ans = 1;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}