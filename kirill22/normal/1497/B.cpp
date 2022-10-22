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
    int n, m, ans = 0;
    cin >> n >> m;
    auto get = [&] (int x) {
        return (m - x) % m;
    };
    multiset<int> a;
    while (n--) {
        int x;
        cin >> x;
        a.insert(x % m);
    }
    while (sz(a)) {
        int x = *a.begin();
        a.erase(a.find(x));
        int l = x, r = x;
        while (sz(a)) {
            if (a.find(get(l)) != a.end()) {
                a.erase(a.find(get(l)));
                l = get(l);
                continue;
            }
            swap(l, r);
            if (a.find(get(l)) != a.end()) {
                a.erase(a.find(get(l)));
                l = get(l);
                continue;
            }
            break;
        }
        ans++;
    }
    cout << ans << '\n';
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