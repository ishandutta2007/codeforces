#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;
const ll INFL = 1.01e18;

void print(vector<ll> a) {
    for (ll x : a) printf("%lld\n", x);
}

const int K = 19;
const int N = 1 << K;


struct segtree {
    int n;
    ll a[N];
    ll mn[K][N];
    int lg[N];

    void init(vector<ll> _a) {
        n = _a.size();
        for (int i = 0; i < n; i++) a[i] = _a[i];

        for (int i = 0; i < K; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                if (i == 0) {
                    mn[i][j] = a[j];
                } else {
                    mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
                }
            }
        }
        lg[0] = -1;
        for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    }

    ll get(int l, int r) {
        if (l > r) return INFL;
        int k = lg[r - l + 1];
        return min(mn[k][l], mn[k][r - (1 << k) + 1]);
    }
};

segtree tr;

int pr[N][K];
ll mnL[N][K];
ll mnR[N][K];

vector<ll> solve(vector<int> p, vector<int> w, vector<int> x, vector<int> l, vector<int> r) {
    int n = p.size();
    int q = x.size();



    vector<int> mn(n, INF), mx(n, -INF);
    for (int i = n - 1; i >= 0; i--) {
        if (mn[i] == INF) {
            mn[i] = mx[i] = i;
        }
        mn[p[i]] = min(mn[p[i]], mn[i]);
        mx[p[i]] = max(mx[p[i]], mx[i]);
    }

    vector<ll> d(n), h(n);
    for (int i = 1; i < n; i++) {
        d[i] = d[p[i]] + w[i];
        h[i] = h[p[i]] + 1;
    }

    vector<ll> cd = d;
    for (int i = 0; i < n; i++) {
        if (mn[i] != i || mx[i] != i) {
            cd[i] = INFL;
        }
    }

    tr.init(cd);

    for (int j = 0; j < K; j++) {
        mnL[0][j] = mnR[0][j] = INFL;
    }
    for (int i = 1; i < n; i++) {
        pr[i][0] = p[i];
        mnL[i][0] = tr.get(mn[p[i]], mn[i] - 1) - 2 * d[p[i]];
        mnR[i][0] = tr.get(mx[i] + 1, mx[p[i]]) - 2 * d[p[i]];
        for (int j = 1; j < K; j++) {
            pr[i][j] = pr[pr[i][j - 1]][j - 1];
            mnL[i][j] = min(mnL[i][j - 1], mnL[pr[i][j - 1]][j - 1]);
            mnR[i][j] = min(mnR[i][j - 1], mnR[pr[i][j - 1]][j - 1]);
        }
    }

    vector<ll> ans;
    for (int i = 0; i < q; i++) {
        ll res = INFL;

        int v = x[i];
        int L = max(mn[v], l[i]);
        int R = min(mx[v], r[i]);

        res = min(res, tr.get(L, R) - d[v]);

        if (l[i] < mn[v]) {
            int cur = v;
            for (int j = K - 1; j >= 0; j--) {
                if (mn[pr[cur][j]] > r[i]) {
                    cur = pr[cur][j];
                }
            }
            if (mn[cur] > r[i]) {
                cur = p[cur];
                res = min(res, tr.get(max(l[i], mn[cur]), r[i]) + d[v] - 2 * d[cur]);
            }
            for (int j = K - 1; j >= 0; j--) {
                if (mn[pr[cur][j]] >= l[i]) {
                    res = min(res, mnL[cur][j] + d[v]);
                    cur = pr[cur][j];
                }
            }
            res = min(res, tr.get(l[i], mn[cur] - 1) + d[v] - 2 * d[p[cur]]);
        }

        if (r[i] > mx[v]) {
            int cur = v;
            for (int j = K - 1; j >= 0; j--) {
                if (mx[pr[cur][j]] < l[i]) {
                    cur = pr[cur][j];
                }
            }
            if (mx[cur] < l[i]) {
                cur = p[cur];
                res = min(res, tr.get(l[i], min(r[i], mx[cur])) + d[v] - 2 * d[cur]);
            }
            for (int j = K - 1; j >= 0; j--) {
                if (mx[pr[cur][j]] <= r[i]) {
                    res = min(res, mnR[cur][j] + d[v]);
                    cur = pr[cur][j];
                }
            }
            res = min(res, tr.get(mx[cur] + 1, r[i]) + d[v] - 2 * d[p[cur]]);
        }

        ans.push_back(res);
    }
    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    int n, q;
    bool first =1 ;
    while (scanf("%d%d", &n, &q) == 2) {
        if (first) first = 0;
        else printf("\n");

        vector<int> p(n), w(n);
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &p[i], &w[i]);
            p[i]--;
        }

        vector<int> x(q), l(q), r(q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d%d", &x[i], &l[i], &r[i]);
            x[i]--;
            l[i]--;
            r[i]--;
        }

        print(solve(p, w, x, l, r));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}