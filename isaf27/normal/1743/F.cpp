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
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 200;

typedef array<array<int, 2>, 2> mt;

mt empty() {
    mt res;
    res[0][0] = 0;
    res[0][1] = 0;
    res[1][0] = 0;
    res[1][1] = 0;
    return res;
}

mt get(int j) {
    mt ans;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        ans[i][i | j]++;
        ans[i][i & j]++;
        ans[i][i ^ j]++;
    }
    return ans;
}

mt tree[T];

mt operator+(const mt& a, const mt& b) {
    mt res;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int h = 0; h < 2; h++) {
                res[i][h] = math::sum(res[i][h], math::mul(a[i][j], b[j][h]));
            }
        }
    }
    return res;

}

void build(int i, int l, int r) {
    if (r - l == 1) {
        tree[i] = get(0);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

void upd(int i, int l, int r, int p, int x) {
    if (r - l == 1) {
        tree[i] = get(x);
        return;
    }
    int mid = (l + r) / 2;
    if (p < mid) {
        upd(2 * i + 1, l, mid, p, x);
    } else {
        upd(2 * i + 2, mid, r, p, x);
    }
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int n;
vector<int> open[M], close[M];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        open[l].emplace_back(i);
        close[r].emplace_back(i);
    }

    build(0, 0, n - 1);
    int st = 0;

    int ans = 0;
    for (int x = 0; x < M; x++) {
        for (int i : open[x]) {
            if (i > 0) {
                upd(0, 0, n - 1, i - 1, 1);
            } else {
                st = 1;
            }
        }
        ans = math::sum(ans, tree[0][st][1]);
        for (int i : close[x]) {
            if (i > 0) {
                upd(0, 0, n - 1, i - 1, 0);
            } else {
                st = 0;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}