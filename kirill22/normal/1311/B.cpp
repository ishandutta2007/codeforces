#include<bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), p(m), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        b = a;
        for (int i = 0; i < m; i++) cin >> p[i];
        for (int i = 0; i < m; i++) p[i]--;
        sort(p.begin(), p.end());
        sort(b.begin(), b.end());
        int l = p[0], cnt = 1;
        for (int i = 1; i < m; i++) {
            if (p[i] == l + cnt) cnt++;
            else {
                int r = l + cnt;
                for (int j2 = l; j2 <= r; j2++) {
                    for (int j = l; j < r; j++) {
                        if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
                    }
                }
                l = p[i];
                cnt = 1;
            }
        }
        int r = l + cnt;
        for (int j2 = l; j2 <= r; j2++) {
            for (int j = l; j < r; j++) {
                if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
            }
        }
        //for (auto x : a) cout << x << "F" << " ";
        if (a == b) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}