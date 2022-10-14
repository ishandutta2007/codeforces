#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, m, sol;
int par[MAXN], bio[MAXN];
vector <int> v[MAXN], r;

int nadi (int x) {
    if (x == par[x]) return x;
    return par[x] = nadi(par[x]);
}

void spoji (int x, int y) {
    par[nadi(y)] = nadi(x);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size() * 2 < n) r.push_back(i);
    }
    for (int i = 1; i < r.size(); i++) {
        spoji(r[i - 1], r[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size() * 2 >= n) {
            memset(bio, 0, sizeof bio);
            for (auto sus : v[i]) bio[sus] = 1;
            for (int j = 1; j <= n; j++) {
                if (j != i && bio[j] == 0) spoji(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++) sol += par[i] == i;
    cout << sol - 1;
    return 0;
}