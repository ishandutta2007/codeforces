#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, sol;
vector <int> v[MAXN];
int dist[MAXN], par[MAXN], dp[MAXN];

void dfs (int x, int rod) {
    par[x] = rod;
    dist[x] = dist[rod] + 1;
    for (auto sus : v[x]) {
        if (sus != rod) dfs(sus, x);
    }
}

int f (int x, int rod) {
    if (v[x].size() == 1) return 1;
    if (v[x].size() != 3) return 0;
    if (dp[x] != -1) return dp[x];
    int a = -1, b = -1;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        if (a == -1) a = f(sus, x); else b = f(sus, x);
    }
    if (a != b) return dp[x] = 0;
    return dp[x] = a + 1;
}

int ok (int x, int rod) {
    vector <int> ch;
    for (auto sus : v[x]) {
        if (sus != rod) ch.push_back(sus);
    }
    if (rod == 0 && ch.size() != 2) return 0;
    if (ch.size() == 2) {
        int a = f(ch[0], x), b = f(ch[1], x);
        if (a == 0 && b == 0) return 0;
        if (a > 0) {
            if (ok(ch[1], x) != a) return 0;
            return a + 1;
        } else {
            if (ok(ch[0], x) != b) return 0;
            return b + 1;
        }
    } else if (ch.size() == 1) {
        if (f(ch[0], x) == 1) sol = x;
        if (sol) return 2; return 0;
    } else if (ch.size() == 3) {
        int a = f(ch[0], x), b = f(ch[1], x), c = f(ch[2], x);
        if (a == 0 || b == 0 || c == 0) return 0;
        if (a == b && c == a + 1 || a == c && b == a + 1 || b == c && a == b + 1) sol = x;
        if (sol) return max(a, max(b, c)) + 1; return 0;
    }
    return 0;
}

void dijametar () {
    int mx = 0, ind = 1;
    for (int br = 0; br < 2; br++) {
        dfs(ind, 0);
        mx = 0, ind = 0;
        for (int i=1; i<=n; i++) {
            if (dist[i] > mx) {
                mx = dist[i];
                ind = i;
            }
        }
    }
    for (int i=0; i<(mx - 1)/2; i++) {
        ind = par[ind];
    }
    if (mx % 2 == 0) {
        if (f(ind, par[ind]) > 0 && f(par[ind], ind) > 0) {
            cout << 2 << endl;
            if (ind < par[ind]) cout << ind << " " << par[ind]; else cout << par[ind] << " " << ind;
        } else {
            cout << 0;
        }
    } else {
        if (ok(ind, 0) == 0) cout << 0; else cout << 1 << endl << sol;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    n = (1 << n) - 2;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dijametar();
    return 0;
}