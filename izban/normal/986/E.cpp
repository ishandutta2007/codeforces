#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int MOD = 1000000007;

int bin(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return res;
}

int inv(int x) {
    return bin(x, MOD - 2);
}
const int M = (int)1.01e7;

int lp[M];
int lb[M];
vector<int> pr;

void init() {
    memset(lp, -1, sizeof(lp));
    memset(lb, -1, sizeof(lb));
    for (int i = 2; i < M; i++) {
        if (lp[i] == -1) {
            lp[i] = i;
            lb[i] = pr.size();
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && 1LL * i * pr[j] < M && pr[j] <= lp[i]; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
}

const int K = 17;
const int N = 1 << K;

int n;
vector<int> e[N];
int a[N];
vector<int> vct;
int in[N], out[N];
int h[N];
int p[N][K];
const int PR = 7e5;
vector<int> vert[PR];
vector<pair<int, int>> qq[PR];
int q;
int uu[N], vv[N], xx[N];
int ans[N];

void dfs1(int v, int pr, int ch) {
    h[v] = ch;
    p[v][0] = pr;
    for (int i = 1; i < K; i++) p[v][i] = p[p[v][i - 1]][i - 1];

    in[v] = vct.size();
    vct.push_back(v);
    for (int to : e[v]) {
        if (to == pr) continue;
        dfs1(to, v, ch + 1);
    }
    out[v] = vct.size();
}

int getP(int v, int h) {
    for (int i = 0; i < K; i++) if (h & (1 << i)) v = p[v][i];
    return v;
}

bool isParent(int p, int v) {
    return in[p] <= in[v] && out[v] <= out[p];
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    u = getP(u, h[u] - h[v]);
    if (u == v) return u;
    for (int i = K - 1; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

template <typename T>
struct fenwick {
    int n;
    vector<T> f;

    fenwick() {}

    fenwick(int N) {
        n = N;
        f.assign(N, T(0));
    }

    fenwick(vector<T> a) {
        n = a.size();
        for (int i = 0; i < n; i++) add(i, a[i]);
    }

    void add(int x, T y) {
        for (; x < n; x |= x + 1) f[x] += y;
    }

    T get(int x) {
        T res(0);
        for (; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
        return res;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    // return min i: sum(0, i) > x
    int upper_bound(T x) {
        int k = 1;
        while (2 * k <= n) k *= 2;

        int res = 0;
        while (k > 0) {
            if (f[res + k - 1] <= x) {
                x -= f[res + k - 1];
                res += k;
            }
            k /= 2;
        }
        return res;
    }
};

int cnt_y_in_x(int x, int y) {
    int res = 0;
    while (x % y == 0) {
        x /= y;
        res++;
    }
    return res;
}

int sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    init();
    cerr << pr.size() << endl;

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    n++;
    a[n - 1] = 1;
    e[n - 1].push_back(0);
    e[0].push_back(n - 1);

    dfs1(n - 1, n - 1, 0);
    for (int v : vct) {
        int x = a[v];
        while (x != 1) {
            int y = lp[x], cnt = 0;
            while (x % y == 0) {
                x /= y;
                cnt++;
            }
            vert[lb[y]].push_back(v);
        }
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &uu[i], &vv[i], &xx[i]);
        uu[i]--; vv[i]--;
        ans[i] = 1;

        if (h[uu[i]] < h[vv[i]]) swap(uu[i], vv[i]);
        int w = lca(uu[i], vv[i]);

        int x = xx[i];
        while (x > 1) {
            int y = lp[x], cnt = 0;
            while (x % y == 0) {
                x /= y;
                cnt++;
            }

            if (uu[i] != w) {
                qq[lb[y]].push_back({uu[i], +i + 1});
                qq[lb[y]].push_back({w, -i - 1});
            }
            qq[lb[y]].push_back({vv[i], +i + 1});
            qq[lb[y]].push_back({p[w][0], -i - 1});
        }
    }


    for (int i = 0; i < (int)pr.size(); i++) {
        vector<int> vv;
        for (auto o : vert[i]) vv.push_back(o);
        for (auto cur : qq[i]) vv.push_back(cur.first);
        sort(vv.begin(), vv.end(), [&](int u, int v) {
            return in[u] < in[v];
        });
        vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
        vector<int> nv;
        for (int j = 0; j < (int)vv.size(); j++) {
            nv.push_back(vv[j]);
            if (j + 1 < (int)vv.size()) {
                nv.push_back(lca(vv[j], vv[j + 1]));
            }
        }
        vv = nv;
        sort(vv.begin(), vv.end(), [&](int u, int v) {
            return in[u] < in[v];
        });
        vv.resize(unique(vv.begin(), vv.end()) - vv.begin());

        sort(qq[i].begin(), qq[i].end(), [&](pair<int, int> x, pair<int, int> y) {
            return in[x.first] < in[y.first];
        });

        int pw = 2, co = M;
        while (co > 1) {
            co /= pr[i];
            pw++;
        }

        vector<int> cnt(pw);

        auto add = [&](int x, int coef) {
            int y = 0;
            while (x % pr[i] == 0) {
                x /= pr[i];
                y++;
            }
            cnt[y] += coef;
        };

        int j = 0;

        vector<int> st;
        for (int v : vv) {
            while (!st.empty() && !isParent(st.back(), v)) {
                add(a[st.back()], -1);
                st.pop_back();
            }
            add(a[v], +1);
            st.push_back(v);

            while (j < (int)qq[i].size() && qq[i][j].first == v) {
                int id = abs(qq[i][j].second) - 1;
                int s = sign(qq[i][j].second);
                int z = cnt_y_in_x(xx[id], pr[i]);

                int curSum = 0;
                for (int t = 0; t < pw; t++) {
                    curSum += cnt[t] * min(t, z);
                }
                if (s > 0) {
                    ans[id] = 1LL * ans[id] * bin(pr[i], curSum) % MOD;
                } else {
                    ans[id] = 1LL * ans[id] * inv(bin(pr[i], curSum)) % MOD;
                }
                j++;
            }
        }
    }

    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}