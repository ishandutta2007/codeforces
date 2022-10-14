#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        map<int, int> cl, cr;
        set<pair<int, int>> s;
        map<pair<int, int>, int> m;
        int n, mn, mx, temp;
        cin >> n >> mn >> mx >> temp;
        cout << temp << endl;
        cl[mn] = temp;
        cr[mx] = temp;
        s.insert(make_pair(mn, mx));
        m[make_pair(mn, mx)] = temp;
        for (int i = 0; i < n - 1; i++) {
            int l, r, c;
            cin >> l >> r >> c;
            s.insert(make_pair(l, r));
            if (m[make_pair(l, r)] == 0)
                m[make_pair(l, r)] = c;
            else
                m[make_pair(l, r)] = min(m[make_pair(l, r)], c);
            if (cl[l] == 0)
                cl[l] = c;
            else
                cl[l] = min(cl[l], c);
            if (cr[r] == 0)
                cr[r] = c;
            else
                cr[r] = min(cr[r], c);
            mn = min(mn, l);
            mx = max(mx, r);
            int ans = cl[mn] + cr[mx];
            if (s.count(make_pair(mn, mx)) == 1)
                ans = min(ans, m[make_pair(mn, mx)]);
            cout << ans << endl;
        }
    }
}