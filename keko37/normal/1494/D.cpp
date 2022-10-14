#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int n, cnt;
int a[MAXN][MAXN], c[MAXN], par[MAXN], bio[MAXN];
vector <pi> e[MAXN * 5];
vector <int> v[MAXN], nodes;

int nadi (int x) {
    while (x != par[x]) x = par[x];
    return x;
}

void dfs (int x) {
    bio[x] = 1;
    par[nadi(x)] = cnt;
    for (auto sus : v[x]) {
        if (!bio[sus]) dfs(sus);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cnt = n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i < j) e[a[i][j]].push_back({i, j});
        }
        c[i] = a[i][i];
    }
    for (int i = 1; i <= 5000; i++) {
        if (e[i].empty()) continue;
        for (int j = 1; j <= n; j++) {
            v[j].clear();
            bio[j] = 0;
        }
        nodes.clear();
        for (auto pp : e[i]) {
            int x = pp.first, y = pp.second;
            v[x].push_back(y);
            v[y].push_back(x);
            nodes.push_back(x); nodes.push_back(y);
        }
        for (auto x : nodes) {
            if (!bio[x]) {
                cnt++;
                par[cnt] = cnt;
                c[cnt] = i;
                dfs(x);
            }
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= cnt; i++) cout << c[i] << " "; cout << '\n';
    cout << cnt << '\n';
    for (int i = 1; i < cnt; i++) cout << i << " " << par[i] << '\n';
    return 0;
}