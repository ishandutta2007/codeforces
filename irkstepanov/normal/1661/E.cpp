#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct node {
    int cnt;
    int compId;
    node() : cnt(0), compId(0) {}
};

vector<vector<int> > possible;

vector<node> t;

pair<vector<int>, int> solve(vector<int>& a, vector<int>& b) {
    vector<vector<int> > g(12);
    vector<bool> alive(12, true);
    for (int i = 0; i < 6; ++i) {
        if (a[i] == -1) {
            alive[i] = false;
            continue;
        }
        for (int j = i + 1; j < 6; ++j) {
            if (a[i] == a[j]) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }

    for (int i = 0; i < 6; ++i) {
        if (b[i] == -1) {
            alive[i + 6] = false;
            continue;
        }
        for (int j = i + 1; j < 6; ++j) {
            if (b[i] == b[j]) {
                g[i + 6].pb(j + 6);
                g[j + 6].pb(i + 6);
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (a[i + 3] != -1 && b[i] != -1) {
            g[i + 3].pb(i + 6);
            g[i + 6].pb(i + 3);
        }
    }

    vector<int> compId(12, -1);
    int num = 0;

    vector<int> order = {0, 1, 2, 9, 10, 11, 3, 4, 5, 6, 7, 8};

    for (int i : order) {
        if (!alive[i] || compId[i] != -1) {
            continue;
        }
        queue<int> q;
        compId[i] = num;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (compId[to] == -1) {
                    compId[to] = num;
                    q.push(to);
                }
            }
        }
        ++num;
    }
    vector<int> ans = {compId[0], compId[1], compId[2], compId[9], compId[10], compId[11]};
    int maxx = -1;
    for (int x : ans) {
        maxx = max(maxx, x);
    }
    return {ans, num - maxx - 1};
}

const int nmax = 600;
pair<int, int> mapa[nmax][nmax];
map<vector<int>, int> corr;

node unite(node& x, node& y) {
    if (x.cnt == -1) {
        return y;
    }
    if (y.cnt == -1) {
        return x;
    }
    int a = x.compId, b = y.compId;
    if (mapa[a][b].first != -1) {
        pii p = mapa[a][b];
        node v;
        v.cnt = x.cnt + y.cnt + p.second;
        v.compId = p.first;
        return v;
    }

    pair<vector<int>, int> p = solve(possible[a], possible[b]);
    int z;
    if (!corr.count(p.first)) {
        z = sz(corr);
        corr[p.first] = z;
        possible.pb(p.first);
    } else {
        z = corr[p.first];
    }
    mapa[a][b] = {z, p.second};

    node v;
    v.cnt = x.cnt + y.cnt + p.second;
    v.compId = z;
    return v;
}

vector<vector<int> > a;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].cnt = 0;
        int sum = 0;
        vector<int> compId(6);
        for (int i = 0; i < 3; ++i) {
            sum += a[i][tl];
            if (a[i][tl]) {
                compId[i] = compId[i + 3] = 0;
            } else {
                compId[i] = compId[i + 3] = -1;
            }
        }
        if (sum == 2 && a[1][tl] == 0) {
            compId[2] = compId[5] = 1;
        }
        int z;
        if (!corr.count(compId)) {
            z = sz(corr);
            corr[compId] = z;
            possible.pb(compId);
        } else {
            z = corr[compId];
        }
        t[v].compId = z;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = unite(t[v * 2], t[v * 2 + 1]);
}

node solve(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    if (r <= tm) {
        return solve(v * 2, tl, tm, l, r);
    }
    if (l > tm) {
        return solve(v * 2 + 1, tm + 1, tr, l, r);
    }
    node x = solve(v * 2, tl, tm, l, min(r, tm));
    node y = solve(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return unite(x, y);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < nmax; ++i) {
        for (int j = 0; j < nmax; ++j) {
            mapa[i][j] = {-1, -1};
        }
    }

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    cin >> n;
    t.resize(4 * n);

    a = vector<vector<int> >(3, vector<int>(n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    build(1, 0, n - 1);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        node v = solve(1, 0, n - 1, l, r);
        int ans = v.cnt;
        int maxx = -1;
        vector<int> compId = possible[v.compId];
        for (int i = 0; i < 6; ++i) {
            maxx = max(maxx, compId[i]);
        }
        ans += maxx + 1;
        cout << ans << "\n";
    }

}