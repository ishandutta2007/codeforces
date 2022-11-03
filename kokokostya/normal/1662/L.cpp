#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

struct output {
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct Fen {
    int n = 0; // [0, n)
    vector<int> f;

    Fen() = default;

    Fen(int nn) {
        n = nn;
        f.assign(n, -inf);
    }

    void update(int i, int x) {
        for (int cur = i; cur < n; cur |= (cur + 1))
            f[cur] = max(f[cur], x);
    }

    int get(int i) {
        int res = -inf;
        for (int cur = i; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res = max(res, f[cur]);
        return res;
    }
};

template <class T>
void compress(vector<T>& a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

struct RangeTree {
    int n = 0;
    vector<ll> xs, ys, zs;
    vector<vector<int>> ty, tz;
    vector<Fen> fy, fz;

    RangeTree() = default;

    RangeTree(vector<tuple<ll, ll, ll>> a) {
        for (auto [x, y, z] : a) {
            xs.push_back(x);
            ys.push_back(y);
            zs.push_back(z);
        }
        compress(xs);
        compress(ys);
        compress(zs);
        n = (int) xs.size();
        vector<vector<int>> seq_y(n), seq_z(n);
        for (auto [x, y, z] : a) {
            int px = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            int py = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
            int pz = lower_bound(zs.begin(), zs.end(), z) - zs.begin();
            seq_y[px].push_back(py);
            seq_z[px].push_back(pz);
        }
        ty.resize(4 * n);
        tz.resize(4 * n);
        build(1, 0, n - 1, seq_y, seq_z);
        fy.resize(4 * n);
        fz.resize(4 * n);
        for (int v = 0; v < (int) ty.size(); v++) {
            fy[v] = Fen((int) ty[v].size());
            fz[v] = Fen((int) tz[v].size());
        }
    }

    static void merge(const vector<int>& al, const vector<int>& ar, vector<int>& mem) {
        int sl = (int) al.size();
        int sr = (int) ar.size();
        for (int x, i = 0, j = 0; i < sl || j < sr;) {
            if (j == sr || (i < sl && al[i] < ar[j])) x = al[i++];
            else x = ar[j++];
            if (mem.empty() || mem.back() < x) mem.push_back(x);
        }
    }

    void build(int v, int tl, int tr, const vector<vector<int>>& seq_y, const vector<vector<int>>& seq_z) {
        if (tl == tr) {
            ty[v] = seq_y[tl];
            tz[v] = seq_z[tl];
            compress(ty[v]);
            compress(tz[v]);
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, seq_y, seq_z);
            build(v << 1 | 1, tm + 1, tr, seq_y, seq_z);
            merge(ty[v << 1], ty[v << 1 | 1], ty[v]);
            merge(tz[v << 1], tz[v << 1 | 1], tz[v]);
        }
    }

    void update(int v, int tl, int tr, int x, int y, int z, int val) {
        {
            int pos_y = lower_bound(ty[v].begin(), ty[v].end(), y) - ty[v].begin();
            int pos_z = lower_bound(tz[v].begin(), tz[v].end(), z) - tz[v].begin();
            fy[v].update(pos_y, val);
            fz[v].update(pos_z, val);
        }
        if (tl < tr) {
            int tm = (tl + tr) >> 1;
            if (x <= tm) update(v << 1, tl, tm, x, y, z, val);
            else update(v << 1 | 1, tm + 1, tr, x, y, z, val);
        }
    }

    void update(ll x, ll y, ll z, int val) {
        int px = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        int py = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
        int pz = lower_bound(zs.begin(), zs.end(), z) - zs.begin();
        update(1, 0, n - 1, px, py, pz, val);
    }

    int get(int v, int tl, int tr, int x, int y, int z) {
        if (tr <= x) {
            int pos_y = upper_bound(ty[v].begin(), ty[v].end(), y) - ty[v].begin() - 1;
            int res = fy[v].get(pos_y);
            return res;
        } else if (tl > x) {
            int pos_z = upper_bound(tz[v].begin(), tz[v].end(), z) - tz[v].begin() - 1;
            int res = fz[v].get(pos_z);
            return res;
        } else {
            int tm = (tl + tr) >> 1;
            return max(get(v << 1, tl, tm, x, y, z), get(v << 1 | 1, tm + 1, tr, x, y, z));
        }
    }

    int get(ll x, ll y, ll z) {
        int px = upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
        int py = upper_bound(ys.begin(), ys.end(), y) - ys.begin() - 1;
        int pz = upper_bound(zs.begin(), zs.end(), z) - zs.begin() - 1;
        if (px < 0 || py < 0 || pz < 0) return -inf;
        return get(1, 0, n - 1, px, py, pz);
    }
};

struct input {
    int n, v;
    vector<int> t, a;

    input() = default;

    void read() {
        cin >> n >> v;
        t.resize(n);
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> t[i];
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        t.insert(t.begin(), 0);
        a.insert(a.begin(), 0);
        n++;
        vector<int> crd = a;
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        int sz = (int) crd.size();
        vector<int> dp(n, -inf);
        dp[0] = 0;
        int res = 0;
        vector<tuple<ll, ll, ll>> A(n);
        for (int i = 0; i < n; i++) {
            A[i] = {a[i], 1ll * v * t[i] - a[i], a[i] + 1ll * v * t[i]};
        }
        RangeTree rt(A);
        for (int i = 0; i < n; i++) {
            int mx = -inf;
//            for (int j = i - 1; j >= 0; j--) {
//                if (A[j].first <= A[i].first && A[j].second <= A[i].second)
//                    mx = max(mx, dp[j]);
//                if (B[j].first <= B[i].first && B[j].second <= B[i].second)
//                    mx = max(mx, dp[j]);
//            }
            auto [xi, yi, zi] = A[i];
            if (i > 0) {
                mx = rt.get(xi, yi, zi);
                dp[i] = mx + 1;
                res = max(res, dp[i]);
            }
            rt.update(xi, yi, zi, dp[i]);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return output();
    }
#endif
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

#ifdef DEBUG
void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}
#endif

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}