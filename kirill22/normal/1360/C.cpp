#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(a) a.begin(), a.end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    bool f = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (a[i] % 2);
    if (cnt % 2 == 0) {
        f = true;
    }
    else {
        for (int i = 1; i < n; i++) {
            if (a[i] % 2 != a[i - 1] % 2 && a[i] - 1 == a[i - 1]) f = true;
        }
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}