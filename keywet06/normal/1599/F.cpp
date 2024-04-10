#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int P = 1e9 + 7;

int64 Pow(int64 a, int64 p, int Mod = P) {
    int64 res = 1;
    a %= Mod;
    while (p) {
        if (p & 1) (res *= a) %= Mod;
        p >>= 1, (a *= a) %= Mod;
    }
    return res;
}

int64 gcd(int64 a, int64 b) { return b == 0 ? a : gcd(b, a % b); }

const int N = 5e5;

int64 f0[N], f1[N], f2[N], f3[N];

int64 get(int64 f[], int pos) {
    int64 res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += f[pos];
        if (res >= P) res -= P;
    }
    return res;
}

void add(int64 f[], int pos, int64 val) {
    val = (val % P + P) % P;
    for (; pos < N; pos |= pos + 1) {
        f[pos] += val;
        if (f[pos] >= P) f[pos] -= P;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int64> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    struct Query {
        int l;
        int64 d;
        int id;
    };
    vector<vector<Query>> queries(n);
    for (int i = 0; i < q; ++i) {
        int l, r;
        int64 d;
        cin >> l >> r >> d;
        queries[r - 1].push_back(Query{l - 1, d, i});
    }
    int64 inv6 = Pow(6, P - 2);
    int64 inv2 = Pow(2, P - 2);
    auto gss = [&](int64 n) {
        return n * (n + 1) % P * (n * 2 + 1) % P * inv6 % P;
    };
    map<int64, int> last;
    vector<int> ans(q);
    for (int i = 0; i < n; ++i) {
        if (last.count(a[i])) {
            int pos = last[a[i]];
            add(f0, pos, -1);
            add(f1, pos, -a[i]);
            add(f2, pos, -a[i] * a[i]);
        }
        last[a[i]] = i;
        add(f0, i, 1);
        add(f1, i, a[i]);
        add(f2, i, a[i] * a[i]);
        for (auto query : queries[i]) {
            int64 cnt = get(f0, i) - get(f0, query.l - 1);
            int64 sum = get(f1, i) - get(f1, query.l - 1);
            int64 h = get(f2, i) - get(f2, query.l - 1);
            sum = (sum + P) % P * Pow(query.d, P - 2) % P * 2 % P;
            int64 a = ((sum + cnt - cnt * cnt) % P + P) % P;
            a = a * Pow(cnt, P - 2) % P * inv2 % P;
            h = (h + P) % P;
            int64 need = (gss(a + cnt - 1) - gss(a - 1) + P) % P;
            need = need * query.d % P * query.d % P;
            ans[query.id] = (need == h);
        }
    }
    for (int i = 0; i < q; ++i) cout << (ans[i] ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}