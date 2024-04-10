#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

struct dsu {
    int n;
    vector<int> p;

    dsu(int _n) {
        n = _n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int get(int x) {
        return x == p[x] ? x : p[x] = get(p[x]);
    }

    void uni(int u, int v) {
        u = get(u);
        v = get(v);
        p[v] = u;
    }
};

int fast(int n, vector<int> a) {
    n = 1 << n;
    vector<int> b(n, -1);
    for (int x : a) b[x] = x;

    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                //b[i + k + j] += b[i + j];
                if (b[i + j] != -1) {
                    b[i + k + j] = b[i + j];
                }
            }
        }
    }

    dsu d(n);
    vector<int> wh(n, -1);

    //for (int x : a) wh[x] = x;

    auto add = [&](int pos, int x) {
        if (wh[pos] != -1) {
            d.uni(wh[pos], x);
        }
        wh[pos] = x;
    };

    for (int x : a) {
        add((~x) & (n - 1), x);
    }

    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                if (wh[i + k + j] != -1) {
                    if (b[i + j] != -1) {
                        add(i + j, wh[i + k + j]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] != -1 && wh[i] != -1) {
            //add(b[i], wh[i]);
            d.uni(b[i], wh[i]);
        }
    }

    int ans = 0;
    for (int x : a) ans += d.get(x) == x;
    return ans;
}

int slow(int n, vector<int> a) {
    int m = a.size();
    dsu d(m);
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++ ){
            if ((a[i] & a[j]) == 0) {
                d.uni(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) ans += d.get(i) == i;
    return ans;
}

void stress() {
    for (int it = 0;; it++) {
        cout << it << endl;
        srand(it);

        int n = rand() % 8 + 1;
        int m = rand() % (1 << n) + 1;
        vector<int> a(1 << n);
        iota(a.begin(), a.end(), 0);
        random_shuffle(a.begin(), a.end());
        a.resize(m);

        auto ans1 = fast(n, a);
        auto ans2 = slow(n, a);
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << n << " " << m << endl;
            for (int x : a) cout << x << " "; cout << endl;
            exit(0);
        }
    }
}

void test() {
    int n = 22;
    int m = rand() % (1 << n) + 1;
    vector<int> a(1 << n);
    iota(a.begin(), a.end(), 0);
    random_shuffle(a.begin(), a.end());
    a.resize(m);

    auto ans1 = fast(n, a);
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    //stress();
    //test();
    
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> a(m);
        for (int i = 0; i < m; i++) scanf("%d", &a[i]);

        printf("%d\n", fast(n, a));
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}