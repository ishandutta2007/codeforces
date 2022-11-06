#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define int long long

int get(vector< pair<int, int> > c, int n, int x) {
    for (int i = n - 1; i >= 0; --i) {
        int k = n - i;
        if (c[i].first * k >= x) {
            return i;
        }
    }
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector< pair<int, int> > c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c.begin(), c.end());
    
    int a = get(c, n, x1);
    int b = get(c, a, x2);
    bool rev = false;
    if (b == -1) {
        rev = true;
        a = get(c, n, x2);
        b = get(c, a, x1);
    }
    if (b == -1) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    vector<int> fi, se;
    for (int i = a; i < n; ++i) {
        fi.push_back(c[i].second + 1);
    }
    for (int i = b; i < a; ++i) {
        se.push_back(c[i].second + 1);
    }
    if (rev) fi.swap(se);
    cout << sz(fi) << ' ' << sz(se) << '\n';
    for (auto i: fi) cout << i << ' ';
    cout << '\n';
    for (auto i: se) cout << i << ' ';
    cout << '\n';
}