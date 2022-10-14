#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

typedef long long llint;

int n, m, s;
llint w[MAXN], bio[MAXN], ok[MAXN], d[MAXN];
vector <int> v[MAXN], g[MAXN];

void dfs (int x, int rod) {
    bio[x] = 1;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        if (bio[sus] == 1) {
            ok[x] = 1;
        } else {
            dfs(sus, x);
            g[x].push_back(sus);
        }
    }
}

void cik (int x) {
    d[x] = w[x];
    for (auto sus : g[x]) {
        cik(sus);
        if (ok[sus]) ok[x] = 1;
        d[x] = max(d[x], w[x] + d[sus]);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> w[i];
    }
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> s;
    dfs(s, 0);
    cik(s);
    llint mx = 0, sol = 0;
    for (int i=1; i<=n; i++) {
        if (ok[i] == 0) mx = max(mx, d[i]); else sol += w[i];
    }
    cout << mx + sol;
    return 0;
}