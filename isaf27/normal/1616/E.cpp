#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
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
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 2000;
const int X = 35;

int n;
string s, t;
int tree[M];
vector<int> pos[X];

void add(int i, int x) {
    for (; i < n; i |= i + 1) {
        tree[i] += x;
    }
}

int gett(int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans += tree[i];
    }
    return ans;
}

void solve() {
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        tree[i] = 0;
    }
    string ss = s;
    sort(ss.begin(), ss.end());
    if (ss >= t) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < 26; i++) {
        pos[i].clear();
    }
    for (int i = n - 1; i >= 0; i--) {
        pos[s[i] - 'a'].emplace_back(i);
    }
    ll ans = (ll)n * n;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        int tp = -1;
        for (int x = 0; x <= t[i] - 'a'; x++) {
            if (pos[x].empty()) {
                continue;
            }
            tp = pos[x].back();
            pos[x].pop_back();
            ll prev = cur;
            cur += tp - i;
            cur += (i - gett(tp));
            add(tp, 1);
            if (x == t[i] - 'a') {
                break;
            }
            pos[x].emplace_back(tp);
            ans = min(ans, cur);
            add(tp, -1);
            cur = prev;
            tp = -1;
        }
        if (tp == -1) {
            break;
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