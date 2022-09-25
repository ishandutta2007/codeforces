#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int &ai : a) cin >> ai;
        int L = 0, R = n;
        while (L < R) {
            int M = (L + R) >> 1;
            int ok = 1, tq = q;
            for (int i = M; i < n; i += 1) {
                if (tq <= 0) ok = 0;
                tq -= tq < a[i];
            }
            if (ok) R = M;
            else L = M + 1;
        }
        string s(n, '1');
        for (int i = 0; i < L; i += 1)
            if (a[i] > q) s[i] = '0';
        cout << s << "\n";
    }
    return 0;
}