#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 2005;

int n, mn = 1e9, ind = -1, cnt;
llint x[MAXN], y[MAXN];
int p[MAXN], bio[MAXN], par[MAXN];
vector <int> v;
vector <pi> sol;

llint ccw (pi a, pi b, pi c) {
    return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);
}

bool cmp (int i, int j) {
    return ccw({x[ind], y[ind]}, {x[i], y[i]}, {x[j], y[j]}) < 0;
}

void dfs (int x) {
    if (bio[x]) return;
    bio[x] = cnt;
    dfs(p[x]);
}

int nadi (int x) {
    if (x == par[x]) return x;
    return par[x] = nadi(par[x]);
}

void f (int a, int b) {
    swap(p[a], p[b]);
    sol.push_back({a, b});
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> p[i];
        if (i == p[i]) continue;
        if (y[i] < mn) {
            mn = y[i];
            ind = i;
        }
    }
    if (ind == -1) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (i != p[i] && i != ind) v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto x : v) {
        if (!bio[x]) {
            cnt++;
            dfs(x);
        }
    }
    for (int i = 1; i <= cnt; i++) {
        par[i] = i;
    }
    for (int i = 1; i < v.size(); i++) {
        int a = nadi(bio[v[i - 1]]);
        int b = nadi(bio[v[i]]);
        if (a == b) continue;
        par[a] = b;
        f(v[i - 1], v[i]);
    }
    while (p[ind] != ind) {
        f(ind, p[ind]);
    }
    cout << sol.size() << '\n';
    for (auto pp : sol) cout << pp.first << " " << pp.second << endl;
    return 0;
}