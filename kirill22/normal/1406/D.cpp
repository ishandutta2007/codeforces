#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

void print(int x) {
    if (x >= 0) cout << (x + 1) / 2 << '\n';
    else cout << x / 2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int K = 0;
    vector<int> a(n), st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) st.pb(a[i] - a[i - 1]);
        else st.pb(a[0]);
    }
    for (int i = 1; i < st.size(); i++) K += max(0ll, st[i]);
    print(st[0] + K);
    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        if (l) {
            K -= max(0ll, st[l]);
            st[l] += x;
            K += max(0ll, st[l]);
        }
        else {
            st[0] += x;
        }
        if (r != n - 1) {
            K -= max(0ll, st[r + 1]);
            st[r + 1] -= x;
            K += max(0ll, st[r + 1]);
        }
        print(st[0] + K);
    }
}