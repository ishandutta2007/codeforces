#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n;
int f[MAXN], bio[MAXN], par[MAXN], siz[MAXN];
vector <int> v[MAXN];

void precompute () {
    f[1] = 1;
    for (int i = 2; i <= 32; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

int dfs (int x, int rod, int ind) {
    siz[x] = 1;
    par[x] = rod;
    int res = -1;
    for (auto sus : v[x]) {
        if (sus == rod || bio[sus]) continue;
        int val = dfs(sus, x, ind);
        if (val != -1) res = val;
        siz[x] += siz[sus];
    }
    if (siz[x] == f[ind - 1] || siz[x] == f[ind - 2]) res = x;
    return res;
}

bool calc (int x, int ind) {
    if (ind <= 2) return 1;
    int y = dfs(x, 0, ind);
    if (y == -1) return 0;
    bio[y] = 1;
    if (!calc(par[y], siz[y] == f[ind - 1] ? ind - 2 : ind - 1)) return 0;
    bio[par[y]] = 1; bio[y] = 0;
    if (!calc(y, siz[y] == f[ind - 1] ? ind - 1 : ind - 2)) return 0;
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= 32; i++) {
        if (n == f[i]) {
            if (calc(1, i)) cout << "YES"; else cout << "NO";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}