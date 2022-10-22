#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cout << -1 << endl;
            return;
        }
    }
    int ans = 0;
    for (char c = 'a'; c <= 't'; c++) {
        char mn = 't';
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && a[i] == c) {
                tmp.pb(i);
                mn = min(mn, b[i]);
            }
        }
        if (tmp.size() != 0) {
            ans++;
            for (auto i : tmp) {
                a[i] = mn;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }
}