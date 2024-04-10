#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, q;
    cin >> n >> q;
    
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    vector<int> c(n);
    for (int idx = 0; idx < n; idx++) {
        cin >> c[idx];
        c[idx]--;
    }
    
    for (int Q = 0; Q < q; Q++) {
        long long a, b;
        cin >> a >> b;
        
        vector<long long> ma(n, numeric_limits<long long>::min() / 2);
        int larg1 = 0, larg2 = 0;

        for (int i = 0; i < n; i++) {
            long long m = numeric_limits<long long>::min() / 2;
            if (larg1 != c[i])
                m = max(m, ma[larg1] + v[i] * b);
            if (larg2 != c[i])
                m = max(m, ma[larg2] + v[i] * b);
            m = max(m, ma[c[i]] + v[i] * a);
            m = max(m, v[i] * b);
            ma[c[i]] = max(ma[c[i]], m);

            if (i == 0) {
                larg1 = c[i];
            } else if (larg1 == larg2 && c[i] != larg1) {
                if (m > ma[larg1]) {
                    larg1 = c[i];
                } else {
                    larg2 = c[i];
                }
            } else {
                if (m > ma[larg1]) {
                    if (larg1 != c[i]) larg2 = larg1;
                    larg1 = c[i];
                } else if (m > ma[larg2] && larg1 != c[i]) {
                    larg2 = c[i];
                }
            }
        }

        cout << max(0LL, ma[larg1]) << '\n';
    }

    return 0;
}