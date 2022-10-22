#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x >= 0) {
                a.push_back(x);
            } else {
                b.push_back(-x);
            }
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        if ((int) a.size() == 0 || ((int) b.size() && b[0] > a[0])) {
            swap(a, b);
        }
        long long ans = 0;
        reverse(b.begin(), b.end());
        while ((int) b.size()) {
            int lst = b.back();
            for (int i = 0; i < k && (int) b.size(); i++) {
                b.pop_back();
            }
            ans += lst * 2;
        }
        reverse(a.begin(), a.end());
        int fst = 1;
        while ((int) a.size()) {
            int lst = a.back();
            for (int i = 0; i < k && (int) a.size(); i++) {
                a.pop_back();
            }
            ans += lst * 2;
            if (fst) {
                ans -= lst;
                fst = 0;
            }
        }
        cout << ans << '\n';
    }
}