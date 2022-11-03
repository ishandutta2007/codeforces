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
        return res == o.res;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<pii> t;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        t.assign(4 * n, make_pair(inf, -1));
    }

    void merge(int v) {
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }

    void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = {x, i};
        } else {
            int tm = (tl + tr) >> 1;
            if (i <= tm) update(v << 1, tl, tm, i, x);
            else update(v << 1 | 1, tm + 1, tr, i, x);
            merge(v);
        }
    }

    void update(int i, int x) {
        update(1, 0, n - 1, i, x);
    }

    pii get(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v];
        } else {
            int tm = (tl + tr) >> 1;
            pii res = {inf, -1};
            if (l <= tm) res = min(res, get(v << 1, tl, tm, l, r));
            if (r > tm) res = min(res, get(v << 1 | 1, tm + 1, tr, l, r));
            return res;
        }
    }

    int get(int l, int r) {
        pii tmp = get(1, 0, n - 1, l, r);
        return tmp.second;
    }
};

struct input {
    int n, a, b;
    vector<int> p;

    input() = default;

    void read() {
        cin >> n >> a >> b;
        a--, b--;
        p.resize(n);
        for (auto& x : p)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> dist(n, inf);
        dist[a] = 0;
        queue<int> q;
        q.push(a);
        RangeTree tol(n), tor(n);
        for (int i = 0; i < n; i++) {
            if (i == a)
                continue;
            tol.update(i, -i - p[i]);
            tor.update(i, +i - p[i]);
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            { // to right
                // i <= j
                // j - i <= p[i]
                // j - i <= p[j]

                // i <= j <= i + p[i]
                // j - p[j] <= i

                int l = i;
                int r = min(n - 1, i + p[i]);
                while (1) {
                    int j = tor.get(l, r);
                    if (j == -1) break;
                    if (j - p[j] > i) break;
                    if (dist[j] > dist[i] + 1) {
                        dist[j] = dist[i] + 1;
                        q.push(j);
                        tol.update(j, inf);
                        tor.update(j, inf);
                    } else {
                        break;
                    }
                }
            }
            { // to left
                // j <= i
                // i - j <= p[i]
                // i - j <= p[j]

                // i - p[i] <= j <= i
                // -j-p[j] <= -i

                int l = max(0, i - p[i]);
                int r = i;
                while (1) {
                    int j = tol.get(l, r);
                    if (j == -1) break;
                    if (-j - p[j] > -i) break;
                    if (dist[j] > dist[i] + 1) {
                        dist[j] = dist[i] + 1;
                        q.push(j);
                        tol.update(j, inf);
                        tor.update(j, inf);
                    } else {
                        break;
                    }
                }
            }
        }
        return output{dist[b]};
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
    int t;
    cin >> t;
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