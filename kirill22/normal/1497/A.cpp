#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    set<int> b;
    while (n--) {
        int x;
        cin >> x;
        if (b.find(x) == b.end()) b.insert(x);
        else a.pb(x);
    }
    for (auto x : b) cout << x << " ";
    for (auto x : a) cout << x << " "; cout << '\n';
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