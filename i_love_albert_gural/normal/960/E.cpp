#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

struct data {
    ll ans;
    ll op, ep;
    ll os, es;

    data add_root_to_paths(ll rv) {
        return {
            ans,
            ep + 1,
            op,
            sum(es, prod(ep + 1, rv)),
            sum(os, MOD - prod(op, rv))
        };
    }
};

data solve(vvi &tree, vll &val, int loc, int par) {
    data res = { 0, 0, 0, 0, 0 };
    for (int ch : tree[loc]) {
        if (ch == par) continue;
        data sub = solve(tree, val, ch, loc);

        //cout << "for " << ch << " ans=" << sub.ans << "; " << sub.op << " odd paths have sum " << sub.os;
        //cout << " and " << sub.ep << " even paths have sum " << sub.es << endl;

        for (int i = 0; i < 2; i++) {
            // paths that just stop at the root
            res.ans = sum(res.ans, sum(sub.es, prod(val[loc], sub.ep)));

            // even paths that combine with previous paths
            res.ans = sum(res.ans, prod(sub.es, res.ep));
            res.ans = sum(res.ans, prod(val[loc], prod(sub.ep, res.ep)));
            res.ans = sum(res.ans, prod(res.es, sub.ep));

            // odd paths that combine with previous paths
            res.ans = sum(res.ans, prod(sub.os, res.op));
            res.ans = sum(res.ans, MOD - prod(val[loc], prod(sub.op, res.op)));
            res.ans = sum(res.ans, prod(res.os, sub.op));
        }

        res.ans = sum(res.ans, sub.ans);
        res.op += sub.op;
        res.os = sum(res.os, sub.os);
        res.ep += sub.ep;
        res.es = sum(res.es, sub.es);
    }

    res.ans = sum(res.ans, val[loc]);
    return res.add_root_to_paths(val[loc]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vll val(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
        val[i] %= MOD;
        if (val[i] < 0) val[i] += MOD;
    }

    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    cout << solve(adj, val, 0, 0).ans << endl;
    return 0;
}