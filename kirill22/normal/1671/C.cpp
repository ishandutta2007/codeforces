#include<bits/stdc++.h>

using namespace std;

// fuck life

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            long long l = 0, r = x + 1;
            while (l + 1 < r) {
                long long m = (l + r) / 2;
                long long res = sum + (i + 1) * (m - 1);
                if (res > x) {
                    r = m;
                } else {
                    l = m;
                }
            }
            ans += l;
        }
        cout << ans << '\n';
    }
}