#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n + 1, -1), c(n + 1, -1), d, e;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (b[a[i]] == -1) {
                   b[a[i]] = i;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i];
            if (c[x] == -1) {
                c[x] = i;
                d.push_back(x);
                e.push_back(x);
            }
        }
        n = d.size();
        sort(e.begin(), e.end());
        map<int, int> l;
        for (int i = 1; i < n; i++) {
            l[e[i]] = e[i - 1];
        }
        reverse(d.begin(), d.end());
        map<int, int> st;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int x = d[i];
            if (l.find(x) != l.end() && st.find(l[x]) != st.end() && b[x] >= c[l[x]]) {
                st[x] = st[l[x]] + 1;
                st[l[x]] = 0;
                mx = max(mx, st[x]);
            }
            else {
                st[x] = 1;
                mx = max(mx, 1ll);
            }
        }
        cout << n - mx << endl;
    }
}