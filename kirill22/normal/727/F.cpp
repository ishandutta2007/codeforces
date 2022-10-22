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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), qu(q);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) cin >> qu[i];
    vector<int> can = {(int) 1e18};
    for (auto x : qu) can.pb(x);
    sort(all(can));
    can.resize(unique(all(can)) - can.begin());
    vector<int> dp(n + 1);
    for (int j = 0; j <= n; j++) {
        int l = -1, r = (int) can.size() - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int c = 0, s = can[m];
            multiset<int> b;
            for (auto x : a) {
                s += x;
                b.insert(x);
                while (s < 0) {
                    auto x = *b.begin();
                    s -= x;
                    b.erase(b.find(x));
                    c++;
                }
            }
            if (c <= j) r = m;
            else l = m;
        }
        dp[j] = can[r];
    }
    for (auto x : qu) {
        int l = -1, r = n;
        while (l + 1 < r) { if (dp[(l + r) / 2] > x) { l = (l + r) / 2; } else { r = (l + r) / 2; } };
        cout << r << '\n';
    }
}