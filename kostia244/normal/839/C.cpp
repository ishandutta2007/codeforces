#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
using namespace std;
int n, l, r, leaf = 0;
double ans = 0;
__V<vi> g;

double dfs(int v, int p, int d, double dd) {
    for(auto& i : g[v]) {
        if(i != p)
            dfs(i, v, d+1, dd * (g[v].size() - (p != -1)));
    }
    if(g[v].size() == 1) {
        ans += (double)d / dd;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    for(int i = 1; i < n; i++) {
        cin >> l >> r;
        g[l].pb(r);
        g[r].pb(l);
    }
    dfs(1, -1, 0, 1);
    cout << fixed << setprecision(15) << ans;
}