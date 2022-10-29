#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 998244353;

ll dp[5005][5005];

ll c[5005][5005];

//ll b[5005];
//
//int getans(int n) {
//    int cnt = 0;
//    do {
//        bool flag = true;
//        for (int i = 4; i <= n; i += 2) {
//            if (b[i] <= b[i - 2]) {
//                flag = false;
//                break;
//            }
//        }
//        if (b[1] >= b[2]) flag = false;
//        for (int i = 3; i < n; i += 2) {
//            if (b[i] >= b[i - 1] || b[i] >= b[i + 1]) {
//                flag = false;
//                break;
//            }
//        }
//        if (flag) {
//            cnt++;
////            for(int i = 1; i<= n; ++ i) cerr << b[i] << " ";
////            cerr << endl;
//        }
//    } while (next_permutation(b + 1, b + n + 1));
//    return cnt;
//}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5005; i++) c[0][i] = 1;
    for (ll i = 1; i < 5005; i++) {
        for (ll j = i; j < 5005; j++) {
            c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % mod;
        }
    }

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
//        n = 10;
        for (ll i = 0; i < n + 5; i++) {
            for (ll j = 0; j < n + 5; j++) {
                dp[i][j] = 0;
            }
        }
        map<ll, ll> mp;
        vector<pair<ll, ll> > v;
        for (ll i = 1; i <= n; i++) {
            ll a;
            cin >> a;
//            a = rand() % n + 1;
//            b[i] = a;
            mp[a]++;
        }
//        sort(b + 1, b + 1 + n);
//        for (int i = 1; i <= n; i++) cout << b[i] << ' ';
//        cout << endl;
//        int ans = getans(n);
//        cout << ans << endl;
        for (auto it: mp) {
            v.push_back({it.second, it.first});
        }
        reverse(v.begin(), v.end());
        mp.clear();
        dp[0][0] = 1;
        if (v[0].first != 1) {
            cout << 0 << endl;
            continue;
        }
        if (n == 2) {
            cout << 1 << endl;
            continue;
        }
        ll top = n / 2;
        ll used = 1;
        for (ll i = 1; i < v.size(); i++) {
            for (ll j = 0; j <= n; j++) {
                ll now = (used + j + 1) / 2;
                if (v[i].first == 1) {
                    if (now + 1 == top) {
                        dp[i][j + 2] = (dp[i][j + 2] + dp[i - 1][j]) % mod;
                    } else if (now + 1 <= top) {
                        dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
                    }
                    if (j != 0) dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j] * j) % mod;
                } else {
                    if (j >= v[i].first) {
                        dp[i][j - v[i].first] = (dp[i][j - v[i].first] + dp[i - 1][j] * c[v[i].first][j]) % mod;
                    }
                    if (now + 1 == top) {
                        if (j >= v[i].first - 1) {
                            dp[i][j - v[i].first + 3] =
                                    (dp[i][j - v[i].first + 3] + dp[i - 1][j] * c[v[i].first - 1][j]) %
                                    mod;
                        }
                    } else if (now + 1 <= top) {
                        if (j >= v[i].first - 1) {
                            dp[i][j - v[i].first + 2] =
                                    (dp[i][j - v[i].first + 2] + dp[i - 1][j] * c[v[i].first - 1][j]) %
                                    mod;
                        }
                    }
                }

            }
            used += v[i].first;
        }
        cout << dp[v.size() - 1][0] << endl;
//        if (dp[v.size() - 1][0] != ans) {
//            cin >> b[0];
//        }
    }
}

//#include <bits/stdc++.h>
//using namespace std;
//
//const int  N = 210;
//int a[N],  b[N];
//
//int main() {
//    int n;
//    cin >> n;
//    for(int i = 1;i <= n; ++ i) {
//        cin >> a[i];
//    }
//
//    return 0;
//}