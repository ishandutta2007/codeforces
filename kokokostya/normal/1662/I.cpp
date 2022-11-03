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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n, m;
    vector<int> p, xs;

    input() = default;

    void read() {
        cin >> n >> m;
        p.resize(n);
        for (auto& x : p) cin >> x;
        xs.resize(m);
        for (auto& x : xs) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        xs.push_back(inf + 10);
        xs.push_back(-inf - 10);
        m += 2;
        sort(xs.begin(), xs.end());
        auto check = [&](int l, int r) -> bool {
            int lx = l * 100;
            int rx = r * 100;
            int pos = lower_bound(xs.begin(), xs.end(), lx) - xs.begin();
            if (xs[pos] <= rx) return false;
            int ql = lx + (lx - xs[pos - 1]);
            int qr = rx - (xs[pos] - rx);
            return ql >= qr;
        };
        ll res = 0;
        vector<ll> P(n);
        for (int i = 0; i < n; i++) {
            P[i] = p[i] + (i > 0 ? P[i - 1] : 0);
        }
        for (int l = 0, r = 0; r < n; r++) {
            while (l <= r && !check(l, r)) l++;
            if (l <= r) {
                ll tmp = P[r] - (l > 0 ? P[l - 1] : 0);
                res = max(res, tmp);
            }
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