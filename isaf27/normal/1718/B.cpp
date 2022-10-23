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
const ld pi = acosl(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ld eps = 1e-8;
const ll INF = (ll)(2e18) + 239;
const int BIG = (int)(1e9) + (int)(239); // (int)(2e9) + (int)(1e6)
const int MOD = 998'244'353;
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    inline int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    inline void add(int& a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
    }

    inline int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    inline void make_sub(int& a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
    }

    inline int mul(int a, int b) {
        return (ll)a * (ll)b % (ll)MOD;
    }

    inline int power(int a, int k) {
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

    inline int inv(int a) {
        return power(a, MOD - 2);
    }

    inline int div(int a, int b) {
        return mul(a, inv(b));
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
const int B = 500;
const int X = 50;

ll f[X];

ll getmask(ll x) {
    ll ans = 0;
    for (int i = X - 1; i >= 0 && x > 0; i--) {
        if (x >= f[i]) {
            ans ^= (1LL << (ll)i);
            x -= f[i];
        }
    }
    return ans;
}

void solve() {
    int k;
    cin >> k;
    ll sum = 0;
    vector<int> cnt(X, 0);
    vector<ll> masks;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        sum += x;
        ll mask = getmask(x);
        for (int t = 0; t < X; t++) {
            if ((mask >> (ll)t) & 1LL) {
                cnt[t]++;
            }
        }
        masks.emplace_back(mask);
    }
    if (k == 1 && sum == 1) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < X; i += 2) {
        if (cnt[i] > 0) {
            bool can = false;
            for (ll mask : masks) {
                if ((mask & ((1LL << (ll)(i + 1)) - 1)) == (1LL << (ll)i)) {
                    can = true;
                    break;
                }
            }
            if (!can) {
                continue;
            }
            vector<int> cnt2 = cnt;
            cnt2[i]--;
            for (int j = 0; j < i; j += 2) {
                cnt2[j]++;
            }
            for (int p = 0; p < X; p++) {
                if (cnt2[p] == 0) {
                    bool good = true;
                    for (int j = p + 1; j < X; j++) {
                        if (cnt2[j] != 0) {
                            good = false;
                            break;
                        }
                    }
                    if (good) {
                        cout << "YES\n";
                        return;
                    }
                    break;
                }
                if (cnt2[p] != 1) {
                    break;
                }
            }
        }
    }
    cout << "NO\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < X; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}