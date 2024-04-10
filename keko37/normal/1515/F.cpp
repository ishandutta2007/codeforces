#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 300005;

llint n, m, cost, sum;
llint a[MAXN], bio[MAXN], par[MAXN];
vector < pair <int, int> > v[MAXN], r[MAXN];
vector <int> sol;
set <pi> st;

void dfs (int x) {
    bio[x] = 1;
    for (auto pp : v[x]) {
        int sus = pp.first;
        int ind = pp.second;
        if (!bio[sus]) {
            r[x].push_back({sus, ind});
            r[sus].push_back({x, ind});
            dfs(sus);
        }
    }
}

int nadi (int x) {
    if (x == par[x]) return x;
    return par[x] = nadi(par[x]);
}

void spoji (int x, int y) {
    if (v[x].size() < v[y].size()) swap(x, y);

    st.erase({-a[x], x});
    st.erase({-a[y], y});

    for (auto pp : r[y]) {
        r[x].push_back(pp);
    }
    r[y].clear();

    par[y] = x;
    a[x] += a[y];
    st.insert({-a[x], x});
}

void ispis () {
    for (int i = 1; i <= n; i++) {
        if (par[i] != i) continue;
        cout << "bla " << i << ": ";
        for (auto pp : r[i]) cout << pp.first << " " << pp.second << " ";
        cout << endl;
    }
}

void solve () {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        st.insert({-a[i], i});
    }
    while (st.size() >= 2) {
        int x = st.begin() -> second;
        int y, ind;
        while (1) {
            y = r[x].back().first;
            ind = r[x].back().second;
            r[x].pop_back();
            y = nadi(y);
            if (y != x) break;
        }
        spoji(x, y);
        sol.push_back(ind);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> cost;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= cost;
        sum += a[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }
    if (sum + cost < 0) {
        cout << "NO";
        return 0;
    }
    dfs(1);
    solve();
    cout << "YES\n";
    for (auto e : sol) cout << e << '\n';
    return 0;
}