// HI
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        int L = 0;
        int R = n + 1;
        int mid;
        while (R - L > 1) {
            mid = (L + R) / 2;
            for (int i = 0; i < n; ++i) {
                c[i] = max(0, mid - 1 - a[i]);
            }
            int cnt = 0;
            for (int i = 0; i < n && cnt < mid; ++i) {
                if (c[i] <= cnt && cnt <= b[i]) {
                    ++cnt;
                }
            }
            if (cnt == mid) {
                L = mid;
            } else {
                R = mid;
            }
        }
        cout << L << '\n';
    }



}