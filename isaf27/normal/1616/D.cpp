//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(1e9) + 239;
const int MOD = 998244353; // 1e9 + 7
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    int mul(int a, int b) {
        return 1LL * a * b % MOD;
    }

    int power(int a, int k) {
        int ans = 1;
        int pw = a;
        while (k) {
            if (k & 1) {
                ans = mul(ans, pw);
            }
            pw = mul(pw, pw);
            k >>= 1;
        }
        return ans;
    }
}

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 2000;
const int X = 35;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    for (int i = 0; i < n; i++) {
        a[i] -= x;
    }
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    vector<int> tree(n + 1, -1);
    auto add = [&](int i, int x) {
        for (; i <= n; i |= i + 1) {
            tree[i] = max(tree[i], x);
        }
        return tree[i];
    };
    auto gett = [&](int i) {
        int ans = -1;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            ans = max(ans, tree[i]);
        }
        return ans;
    };
    vector<ll> cd;
    for (auto x : pref) {
        cd.emplace_back(-x);
    }
    sort(cd.begin(), cd.end());
    cd.resize(unique(cd.begin(), cd.end()) - cd.begin());
    vector<pair<int, int>> seg;
    for (int i = 0; i + 2 <= n; i++) {
        int pos = lower_bound(cd.begin(), cd.end(), -pref[i]) - cd.begin();
        add(pos, i);
        pos = lower_bound(cd.begin(), cd.end(), -pref[i + 2]) - cd.begin();
        int lb = gett(pos - 1);
        if (lb != -1) {
            seg.emplace_back(lb, i + 1);
        }
    }
    sort(seg.begin(), seg.end());
    int ans = n;
    int last = -1;
    for (const auto& t : seg) {
        if (last < t.first) {
            ans--;
            last = t.second;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(20);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}