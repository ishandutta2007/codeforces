#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 2005;

int n, root;
int par[MAXN], c[MAXN], siz[MAXN], sol[MAXN];
vector <int> v[MAXN];

void dfs (int x) {
    siz[x] = 1;
    for (auto sus : v[x]) {
        dfs(sus);
        siz[x] += siz[sus];
    }
}

void rjesi (int x, vector <int> r) {
    sol[x] = r[c[x]];
    for (auto sus : v[x]) {
        vector <int> tmp;
        while (tmp.size() < siz[sus]) {
            if (r.back() == sol[x]) {
                r.pop_back();
                continue;
            }
            tmp.push_back(r.back());
            r.pop_back();
        }
        reverse(tmp.begin(), tmp.end());
        rjesi(sus, tmp);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> par[i] >> c[i];
        v[par[i]].push_back(i);
        if (par[i] == 0) root = i;
    }
    dfs(root);
    for (int i = 1; i <= n; i++) {
        if (c[i] >= siz[i]) {
            cout << "NO";
            return 0;
        }
    }
    vector <int> e;
    for (int i = 1; i <= n; i++) e.push_back(i);
    rjesi(root, e);
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    return 0;
}