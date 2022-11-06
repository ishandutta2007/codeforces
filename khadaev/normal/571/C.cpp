#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

using edge = tuple<int, int, int>;
const int N = 2e5 + 10;
vector<edge> e[N];

void dfs(int i, vector<int> &used, vector<int> &ans) {
    if (used[i]) return;
    used[i] = 1;
    for (auto p : e[i]) {
        int j, pos, inv;
        tie(j, pos, inv) = p;
        if (!used[j]) {
            ans[pos] = 1 - inv;
            dfs(j, used, ans);
        }
    }
}

int dfs1(int i, vector<int> &used, int pr = -1) {
    used[i] = 1;
    for (auto p : e[i]) {
        int j;
        tie(j, ignore, ignore) = p;
        if (j == pr) continue;
        if (used[j]) return j;
        int t = dfs1(j, used, i);
        if (t != -1) return t;
    }
    return -1;
}

bool check(int n, vector<vector<pair<int, int>>> &disj, vector<int> &ans) {
    forn(i, 0, n) {
        bool rez = false;
        for (auto p : disj[i]) {
            rez |= (ans[p.fs] ^ !p.sn);
        }
        if (!rez) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> ans(m, -1);
    vector<vector<pair<int, int>>> disj(n);
    vector<vector<pair<int, int>>> pos(m);
    forn(i, 0, n) {
        int k;
        cin >> k;
        int tmp;
        forn(j, 0, k) {
            cin >> tmp;
            disj[i].eb(abs(tmp) - 1, tmp > 0);
            pos[abs(tmp) - 1].eb(i, tmp > 0);
        }
    }
    vector<int> used(n, 0);
    queue<int> q;
    forn(i, 0, m) {
        assert(pos[i].size() <= 2);
        vector<int> u(2, 0);
        for (auto p : pos[i]) {
            u[p.sn] = 1;
        }
        if (!u[0]) {
            if (u[1]) {
                ans[i] = 1;
                for (auto p : pos[i]) {
                    if (!used[p.fs]) q.push(p.fs);
                    used[p.fs] = 1;
                }
            }
        } else if (!u[1]) {
            ans[i] = 0;
            for (auto p : pos[i]) {
                if (!used[p.fs]) q.push(p.fs);
                used[p.fs] = 1;
            }
        }
    }
    //cerr << "USED:\n";
    //trace(used);
    //cerr << '\n';
    while (!q.empty()) {
        int d = q.front();
        //cerr << "D = " << d << '\n';
        q.pop();
        for (auto p : disj[d]) {
            for (auto x : pos[p.fs]) {
                if (x.fs == d) continue;
                if (used[x.fs]) continue;
                //cerr << p.fs << '\n';
                ans[p.fs] = x.sn;
                q.push(x.fs);
                used[x.fs] = 1;
            }
        }
    }
    //cerr << '\n';
    vector<int> used1(n);
    forn(i, 0, m) {
        int u = -1, v = -1;
        for (auto p : pos[i]) {
            if (p.sn == 0) u = p.fs;
            else v = p.fs;
        }
        if (u == -1 || v == -1 || used[u] || used[v])
            continue;
        e[u].eb(v, i, 0);
        e[v].eb(u, i, 1);
    }
    forn(i, 0, n) if (!used[i]) {
        int u = dfs1(i, used1);
        if (u == -1) u = i;
        dfs(u, used, ans);
        for (auto p : e[u]) {
            int j, ps, inv;
            tie(j, ps, inv) = p;
            if (ans[ps] == -1) ans[ps] = inv;
        }
    }
    forn(i, 0, m) if (ans[i] == -1) ans[i] = 0;
    if (!check(n, disj, ans)) {
        cout << "NO\n";
        //forn(i, 0, m) cout << ans[i];
        return 0;
    }
    cout << "YES\n";
    forn(i, 0, m) cout << ans[i];
}