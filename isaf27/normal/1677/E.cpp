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
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 19) + 239;
const int B = 500;
const int X = (int)(1e6 + 239);

ll tree[T], add[T];

void build(int i, int l, int r) {
    tree[i] = 0;
    add[i] = 0;
    if (r - l == 1) {
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
}

void push(int i, int l, int r) {
    tree[i] += add[i] * (r - l);
    if (r - l != 1) {
        add[2 * i + 1] += add[i];
        add[2 * i + 2] += add[i];
    }
    add[i] = 0;
}

void upd(int i, int l, int r, int ql, int qr, int x) {
    push(i, l, r);
    if (qr <= l || r <= ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        add[i] += x;
        push(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * i + 1, l, mid, ql, qr, x);
    upd(2 * i + 2, mid, r, ql, qr, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

ll getsum(int i, int l, int r, int ql, int qr) {
    push(i, l, r);
    if (qr <= l || r <= ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return tree[i];
    }
    int mid = (l + r) / 2;
    return getsum(2 * i + 1, l, mid, ql, qr) + getsum(2 * i + 2, mid, r, ql, qr);
}

int n, q, p[M], ip[M];
int vl[M], vr[M];

vector<int> d[M];

ll ans[X];
int l[X], r[X];
vector<int> lq[M], rq[M];
vector<pair<int, int>> al[M], ar[M];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(1);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        ip[p[i]] = i;
    }
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
        lq[l[i]].emplace_back(i);
        rq[r[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            d[j].emplace_back(i);
        }
    }

    vector<int> pos;
    for (int i = 0; i < n; i++) {
        while (!pos.empty() && p[pos.back()] < p[i]) {
            pos.pop_back();
        }
        if (pos.empty()) {
            vl[i] = -1;
        } else {
            vl[i] = pos.back();
        }
        pos.emplace_back(i);
    }
    pos.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!pos.empty() && p[pos.back()] < p[i]) {
            pos.pop_back();
        }
        if (pos.empty()) {
            vr[i] = n;
        } else {
            vr[i] = pos.back();
        }
        pos.emplace_back(i);
    }

    for (int i = 1; i <= n; i++) {
        int D = ip[i - 1];
        int L = vl[D] + 1;
        int R = vr[D] - 1;
        vector<pair<int, int>> segs;
        for (int x : d[i]) {
            int y = i / x;
            if (y <= x) {
                continue;
            }
            int px = ip[x - 1];
            int py = ip[y - 1];
            if (!(L <= px && px <= R)) {
                continue;
            }
            if (!(L <= py && py <= R)) {
                continue;
            }
            int gl = min(min(px, py), D);
            int gr = max(max(px, py), D);
            segs.emplace_back(gl, gr);
        }
        if (D - L <= R - D) {
            vector<int> bd(D - L + 1, R + 1);
            for (const auto& t : segs) {
                bd[t.first - L] = min(bd[t.first - L], t.second);
            }
            int cr = R + 1;
            for (int ps = D; ps >= L; ps--) {
                cr = min(cr, bd[ps - L]);
                if (cr <= R) {
                    al[ps].emplace_back(cr, R);
                }
            }
        } else {
            vector<int> bd(R - D + 1, L - 1);
            for (const auto& t : segs) {
                bd[t.second - D] = max(bd[t.second - D], t.first);
            }
            int cl = L - 1;
            for (int ps = D; ps <= R; ps++) {
                cl = max(cl, bd[ps - D]);
                if (cl >= L) {
                    ar[ps].emplace_back(L, cl);
                }
            }
        }
    }

    build(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (const auto& t : ar[i]) {
            upd(0, 0, n, t.first, t.second + 1, 1);
        }
        for (int j : rq[i]) {
            ans[j] += getsum(0, 0, n, l[j], i + 1);
        }
    }

    build(0, 0, n);
    for (int i = n - 1; i >= 0; i--) {
        for (const auto& t : al[i]) {
            upd(0, 0, n, t.first, t.second + 1, 1);
        }
        for (int j : lq[i]) {
            ans[j] += getsum(0, 0, n, i, r[j] + 1);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}