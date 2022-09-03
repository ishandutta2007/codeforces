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
const int alf = 26;
const ld eps = 1e-8;
const ll INF = (ll)(2e18) + 239;
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
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1010;

int fact[M], inv[M];

int n, c[M];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        c[x]++;
    }
    vector<int> pos;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] != 0) {
            pos.emplace_back(i);
            d = gcd(d, c[i]);
        }
    }
    if (d == n) {
        cout << "1\n";
        return;
    }
    vector<int> dv;
    for (int i = d; i >= 1; i--) {
        if (d % i == 0) {
            dv.emplace_back(i);
        }
    }
    vector<int> sum(dv.size());
    vector<int> cnt(dv.size());
    for (int it = 0; it < (int)dv.size(); it++) {
        int p = dv[it];
        int cur = 0;
        int cun = fact[n / p];
        //cerr << cun << "\n";
        for (int i : pos) {
            int f = c[i] / p;
            cur = math::sum(cur, math::mul(f, f - 1));
            cun = math::mul(cun, inv[f]);
        }
        cur = math::mul(n, cur);
        cur = math::mul(cur, math::power(math::mul(n / p, (n / p) - 1), MOD - 2));
        cur = math::mul(cur, cun);
        //cerr << p << " " << cur << " " << cun << "\n";
        for (int j = 0; j < it; j++) {
            if (dv[j] % p == 0) {
                cur = math::sub(cur, sum[j]);
                cun = math::sub(cun, cnt[j]);
            }
        }
        //cur = math::mul(cur, invv);
        //cerr << invv << "\n";
        //cerr << cun << "<-\n";
        //cun = math::mul(cun, invv);
        sum[it] = cur;
        cnt[it] = cun;
        //cerr << "final: " << cur << " " << cun << "\n";
    }
    int ssum = 0;
    int scnt = 0;
    for (int it = 0; it < (int)dv.size(); it++) {
        int p = dv[it];
        int invv = math::mul(inv[n / p], fact[(n / p) - 1]);
        ssum = math::sum(ssum, math::mul(sum[it], invv));
        scnt = math::sum(scnt, math::mul(cnt[it], invv));
    }
    cout << math::sub(n, math::mul(ssum, math::power(scnt, MOD - 2))) << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(1);

    fact[0] = 1;
    for (int i = 1; i < M; i++) {
        fact[i] = math::mul(fact[i - 1], i);
    }
    inv[M - 1] = math::power(fact[M - 1], MOD - 2);
    for (int i = M - 1; i > 0; i--) {
        inv[i - 1] = math::mul(inv[i], i);
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}