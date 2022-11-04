#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi g;
vi fir;
vi sec;

void dfs(int v, int p, int now) {
    if(now == 0) {
        fir.push_back(v);
    } else {
        sec.push_back(v);
    }
    for(int u : g[v]) {
        if(u == p) continue;
        dfs(u, v, 1 - now);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        g.assign(n, vi(0));
        for(int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        fir.clear();
        sec.clear();
        dfs(0, -1, 0);
        if(fir.size() > sec.size()) {
            swap(fir, sec);
        }
        int ch = fir.size();
        vi ans(n);
        int now = 0;
        unordered_set<int> all;
        for(int i = 1; i <= n; i++) {
            all.insert(i);
        }
        all.reserve(4 * n);
        for(int i = 0; i < 25; i++) {
            if((ch >> i) & 1) {
                for(int j = 1 << i; j < (1 << (i + 1)); j++) {
                    ans[fir[now++]] = j;
                    all.erase(all.find(j));
                }
            }
        }
        for(int i = 0; i < sec.size(); i++) {
            ans[sec[i]] = *(all.begin());
            all.erase(all.begin());
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}