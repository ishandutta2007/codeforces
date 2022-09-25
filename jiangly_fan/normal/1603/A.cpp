#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i += 1) cin >> a[i];
        while (n) {
            int t = n;
            while (a[t] % (t + 1) == 0 and t >= 1) t -= 1;
            if (t == 0) break;
            for (int i = t; i < n; i += 1) a[i] = a[i + 1];
            n -= 1;
        }
        cout << (n ? "NO\n" : "YES\n");
    }
    return 0;
}