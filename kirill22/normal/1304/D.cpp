#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n, -1), c(n, -1);
    set<int> b, d;
    for (int i = 1; i <= n; i++) {
        b.insert(-i);
        d.insert(i);
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '>') {
            a[i] = -(*b.begin());
            b.erase(b.begin());
            continue;
        }
        int l = i;
        int r = i;
        while (r < n - 2 && s[r + 1] == '<') {
            r++;
        }
        int z = (*b.begin());
        b.erase(b.begin());
        for (int j = r; j >= l; j--) {
            a[j] = -(*b.begin());
            b.erase(b.begin());
        }
        b.insert(z);
        i = r;
    }
    a[n - 1] = -(*b.begin());
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '<') {
            c[i] = *d.begin();
            d.erase(d.begin());
            continue;
        }
        int l = i;
        int r = i;
        while (r < n - 2 && s[r + 1] == '>') {
            r++;
        }
        int z = *d.begin();
        d.erase(d.begin());
        for (int j = r; j >= l; j--) {
            c[j] = *d.begin();
            d.erase(d.begin());
        }
        d.insert(z);
        i = r;
    }
    c[n - 1] = *d.begin();
    for (auto el : a) cout << el << " ";
    cout << endl;
    for (auto el : c) cout << el << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}