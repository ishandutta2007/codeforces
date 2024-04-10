#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q; while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int s = 0, s2 = 0, cnt = 0;
        int lst = 0, lst2 = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            if (cnt % 2 == 0) {
                lst = 0;
                while (i <= j && lst <= lst2) {
                    s += a[i];
                    lst += a[i];
                    i++;
                }
                cnt++;
            }
            else {
                lst2 = 0;
                while (i <= j && lst2 <= lst) {
                    s2 += a[j];
                    lst2 += a[j];
                    j--;
                }
                cnt++;
            }
        }
        cout << cnt << " " << s << " " << s2 << endl;
    }
}