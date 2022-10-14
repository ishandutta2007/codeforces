#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;

int n, k, cnt, ok = 1;
int par[MAXN], nxt[MAXN], in[MAXN], out[MAXN], col[MAXN], pos[MAXN], bio[MAXN];
vector <int> comp[MAXN], v[MAXN], r;

void idi (int x) {
    col[x] = cnt;
    comp[cnt].push_back(x);
    if (nxt[x] != 0) {
        idi(nxt[x]);
        pos[x] = 1 + pos[nxt[x]];
    } else {
        pos[x] = 0;
    }
}

void dfs (int x) {
    bio[x] = 1;
    for (auto sus : v[x]) {
        if (bio[sus] == 0) {
            dfs(sus);
        } else if (bio[sus] == 1) {
            ok = 0;
        }
    }
    r.push_back(x);
    bio[x] = 2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> par[i];
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        nxt[a] = b;
        out[a]++; in[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (out[i] > 1 || in[i] > 1) {
            cout << 0;
            return 0;
        }
        if (in[i] == 0) {
            cnt++;
            idi(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) ok = 0;
        if (par[i] == 0) continue;
        if (col[par[i]] != col[i]) {
            v[col[par[i]]].push_back(col[i]);
        } else {
            if (pos[par[i]] < pos[i]) ok = 0;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (bio[i] == 0) dfs(i);
    }
    if (!ok) {
        cout << 0;
        return 0;
    }
    reverse(r.begin(), r.end());
    for (auto x : r) {
        for (auto y : comp[x]) cout << y << " ";
    }
    return 0;
}