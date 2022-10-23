#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 60;

int s[M][X];
unsigned int h[2 * M][X];
vector<int> vx;
int n, q, a[M];
vector<tuple<int, int, int>> qr;

ll res[X];

void add(int i, int x, int z) {
    for (; i < n; i |= i + 1) {
        for (int t = 0; t < X; t++) {
            if (z == 1) {
                s[i][t] += h[x][t];
            } else {
                s[i][t] -= h[x][t];
            }
        }
    }
}

void calc(int l, int r) {
    for (int t = 0; t < X; t++) {
        res[t] = 0;
    }
    l--;
    for (; l >= 0; l = (l & (l + 1)) - 1) {
        for (int t = 0; t < X; t++) {
            res[t] -= s[l][t];
        }
    }
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        for (int t = 0; t < X; t++) {
            res[t] += s[r][t];
        }
    }
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vx.emplace_back(a[i]);
    }
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int id, x;
            cin >> id >> x;
            vx.emplace_back(x);
            id--;
            qr.emplace_back(-1, id, x);
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            qr.emplace_back(l, r, x);
        }
    }
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin();
    }
    for (auto& t : qr) {
        if (get<0>(t) == -1) {
            get<2>(t) = lower_bound(vx.begin(), vx.end(), get<2>(t)) - vx.begin();
        }
    }
    for (int i = 0; i < vx.size(); i++) {
        for (int t = 0; t < X; t++) {
            h[i][t] = rnd() % 2;
        }
    }
    for (int i = 0; i < n; i++) {
        add(i, a[i], 1);
    }
    for (const auto& [l, r, k] : qr) {
        if (l >= 0) {
            calc(l, r);
            bool fnd = false;
            for (int t = 0; t < X; t++) {
                if (res[t] % k != 0) {
                    cout << "NO\n";
                    fnd = true;
                    break;
                }
            }
            if (!fnd) {
                cout << "YES\n";
            }
        } else {
            add(r, a[r], -1);
            a[r] = k;
            add(r, a[r], 1);
        }
    }

    return 0;
}