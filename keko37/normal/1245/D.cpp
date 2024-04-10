#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 2005;

llint n, sol;
llint x[MAXN], y[MAXN], c[MAXN], k[MAXN], par[MAXN];
vector < pair <llint, pair <int, int> > > v;
vector <int> r;
vector < pair <int, int> > e;

int nadi (int x) {
    if (x == par[x]) return x;
    return par[x] = nadi(par[x]);
}

bool spoji (int a, int b) {
    a = nadi(a); b = nadi(b);
    if (a == b) return 0;
    par[b] = a;
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        par[i] = i;
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> k[i];
    for (int i = 1; i <= n; i++) {
        v.push_back({c[i], {0, i}});
        for (int j = i - 1; j >= 1; j--) {
            v.push_back({(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), {i, j}});
        }
    }
    sort(v.begin(), v.end());
    for (auto par : v) {
        llint w = par.first;
        int a = par.second.first, b = par.second.second;
        if (a > b) swap(a, b);
        if (spoji(a, b)) {
            sol += w;
            if (a == 0) r.push_back(b); else e.push_back({a, b});
        }
    }
    cout << sol << endl;
    cout << r.size() << endl;
    for (auto i : r) cout << i << " "; cout << endl;
    cout << e.size() << endl;
    for (auto i : e) cout << i.first << " " << i.second << endl;
    return 0;
}