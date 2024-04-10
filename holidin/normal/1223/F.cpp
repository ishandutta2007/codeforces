#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 3e5 + 1;
const int mod1 = 1e9 + 9;
const int mod2 = 1e9 + 7;
const int div1 = 500009;
const int div2 = 500069;
int a[N];

int DaC(int l, int r) {
    if (l >= r - 1)
        return 0;
    int ans = DaC(l, (l + r) / 2) + DaC((l + r) / 2, r);
    map <pair<int, int> , int> m;
    vector <int> v, hesh1, hesh2;
    hesh1.push_back(0);
    hesh2.push_back(0);
    for (int i = (l + r) / 2 - 1; i >= l; --i) {
        if (v.size() == 0 || v[v.size() - 1] != a[i]) {
            v.push_back(a[i]);
            hesh1.push_back({(hesh1.back() * div1 + a[i]) % mod1});
            hesh2.push_back({(hesh2.back() * div2 + a[i]) % mod1});
        } else {
            v.resize(v.size() - 1);
            hesh1.resize(hesh1.size() - 1);
            hesh2.resize(hesh2.size() - 1);
        }
        ++m[{hesh1.back(), hesh2.back()}];
    }
    v.clear();
    hesh1.resize(1);
    hesh2.resize(1);
    for (int i = (l + r) / 2; i < r; ++i) {
        if (v.size() == 0 || v[v.size() - 1] != a[i]) {
            v.push_back(a[i]);
            hesh1.push_back({(hesh1.back() * div1 + a[i]) % mod1});
            hesh2.push_back({(hesh2.back() * div2 + a[i]) % mod1});
        } else {
            v.resize(v.size() - 1);
            hesh1.resize(hesh1.size() - 1);
            hesh2.resize(hesh2.size() - 1);
        }
        ans += m[{hesh1.back(), hesh2.back()}];
    }
    return ans;
}


void solve() {
    int i, j, k, n;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    cout << DaC(1, n + 1) << "\n";
}

signed main() {
    int test, i;
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test;
    for (i = 0; i < test; ++i)
        solve();
}