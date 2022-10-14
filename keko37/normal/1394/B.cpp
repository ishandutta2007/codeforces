#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n, m, k, sol;
vector <int> v[MAXN];
vector <pi> to[MAXN];
bool e[11][11][11][11];
int c[11];
int cnt[11][11];

inline int get (int x, int w) {
    return lower_bound(v[x].begin(), v[x].end(), w) - v[x].begin() + 1;
}

void obradi (int x) {
    vector <pi> r;
    memset(cnt, 0, sizeof cnt);
    for (auto par : to[x]) {
        int sus = par.first, w = par.second;
        int d = v[sus].size(), g = get(sus, w);
        r.push_back({d, g});
        cnt[d][g]++;
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    for (auto a : r) {
        for (auto b : r) {
            if (a == b) continue;
            e[a.first][a.second][b.first][b.second] = 1;
            e[b.first][b.second][a.first][a.second] = 1;
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            if (cnt[i][j] >= 2) e[i][j][i][j] = 1;
        }
    }
}

bool check (int len) {
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= i; j++) {
            if (e[i][c[i]][j][c[j]]) return 0;
        }
    }
    return 1;
}

void calc (int pos) {
    if (pos == k + 1) {
        sol++;
        return;
    }
    for (int i = 1; i <= pos; i++) {
        c[pos] = i;
        if (check(pos)) calc(pos + 1);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(c);
        to[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 1; i <= n; i++) obradi(i);
    calc(1);
    cout << sol;
    return 0;
}