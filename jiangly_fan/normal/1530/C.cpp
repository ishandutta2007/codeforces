#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> a(n), b(n);
        for (LL& x : a) cin >> x;
        for (LL& x : b) cin >> x;
        sort(a.begin(), a.end(), greater<LL>());
        sort(b.begin(), b.end(), greater<LL>());
        LL L = 0, R = 1E9;
        while (L < R) {
            LL M = (L + R) >> 1;
            LL N = (n + M) - (n + M) / 4;
            LL A = min(M, N) * 100;
            for (int i = 0; i < N - (int)min(M, N); i += 1)
                A += a[i];
            LL B = 0;
            for (int i = 0; i < min(n, (int)N); i += 1)
                B += b[i];
            if (A >= B) R = M;
            else L = M + 1;
        }
        cout << L << "\n";
    }
    return 0;
}