#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
using namespace std;
int n, m, l, r, md, e = 0, c = 1, k = 0, ans = 0;
bool can;
vi col, t;
__V<vi> g;

void dfs(int v, int p = -1) {
    col[v] = c;
    k++;
    int deg = 0;
    for(auto& i : g[v]) {
        deg++;
        if(col[i] == 0) {
            dfs(i, v);
        }
        e++;
    }
    can &= (deg == 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    col.resize(n, 0);
    g.resize(n);
    while(m--) {
        cin >> l >> r, l--, r--;
        g[l].pb(r);
        g[r].pb(l);
    }
    for(int i = 0; i < n; i++) {
        if(col[i] == 0) {
            k = e = md = 0;
            t.assign(0, n);
            t.pb(i);
            can = 1;
            dfs(i);
            ans += can;
        }
    }
    cout << ans;
}