#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

void print(vector<int> a) {
    printf("%d\n", (int)a.size());
    for (int i = 0; i < (int)a.size(); i++) printf("%d%c", a[i], " \n"[i + 1 == (int)a.size()]);
}

vector<int> fast(int n, int q, vector<int> l, vector<int> r, vector<int> x) {
    const int N = 1 << 14;
    vector<vector<int>> t(N * 2);
    for (int i = 0; i < q; i++) {
        int L = l[i] + N, R = r[i] + N;
        while (L <= R) {
            if (L & 1) t[L].push_back(x[i]);
            if (!(R & 1)) t[R].push_back(x[i]);
            L = (L + 1) >> 1;
            R = (R - 1) >> 1;
        }
    }

    const int NN = 10100;
    bitset<NN> ans;
    function<void(int, int, int, const bitset<NN> &b)> rec = [&](int v, int tl, int tr, bitset<NN> b) {
        for (int x : t[v]) {
            b |= b << x;
        }
        if (tl == tr) {
            if (tl < n) {
                ans |= b;
            }
            return;
        }
        if (tl >= n) return;
        int tm = (tl + tr) >> 1;
        rec(v * 2, tl, tm, b);
        rec(v * 2 + 1, tm + 1, tr, b);
    };
    bitset<NN> start;
    start[0] = 1;
    rec(1, 0, N - 1, start);

    //for (int i = 0; i < 10; i++) cout << ans[i] << " ";
    //cout << endl;

    vector<int> res;
    for (int i = 1; i <= n; i++) if (ans[i]) res.push_back(i);
    return res;
}

void test() {
    int n = 1e4;
    int q = 1e4;
    vector<int> l(q), r(q), x(q);
    for (int i = 0; i < q; i++) {
        l[i] = rand() % (n / 2);
        r[i] = n / 2 + rand() % (n / 2);
        x[i] = rand() % (n / 2);
    }
    fast(n, q, l, r, x);
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    //test();

    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        vector<int> l(q), r(q), x(q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d%d", &l[i], &r[i], &x[i]);
            l[i]--; r[i]--;
        }

        print(fast(n, q, l, r, x));
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}