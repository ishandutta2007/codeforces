#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0, ans2 = 0;
    vector<vector<int>> tmp = {a};
    for (int j = 30; j >= 0; j--) {
        vector<vector<int>> tmp2;
        long long c = 0, c2 = 0;
        for (auto a : tmp) {
            vector<int> X, Y;
            int v = 0, v2 = 0;
            for (auto x : a) {
                if ((x & (1 << j))) {
                    c2 += v;
                    v2++;
                    X.pb(x);
                }
                else {
                    c += v2;
                    v++;
                    Y.pb(x);
                }
            }
            if (X.size() > 0) tmp2.pb(X);
            if (Y.size() > 0) tmp2.pb(Y);
        }
        ans += min(c, c2);
        if (c2 < c) ans2 += (1 << j);
        tmp = tmp2;
    }
    cout << ans << " " << ans2;
}