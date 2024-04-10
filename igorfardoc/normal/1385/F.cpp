#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
        int n, k;
        cin >> n >> k;
        vector<set<int>> g(n);
        vector<set<int>> g1(n);
        for(int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[v].insert(u);
            g[u].insert(v);
        }
        if(k == 1) {
            cout << n - 1 << '\n';
            continue;
        }
        set<pair<int, int>> s;
        for(int i = 0; i < n; i++) {
            int am = 0;
            for(int u : g[i]) {
                if(g[u].size() == 1) {
                    ++am;
                    g1[i].insert(u);
                }
            }
            s.insert({am, i});
        }
        int res = 0;
        while(s.size() > 1) {
            auto p = *(s.rbegin());
            s.erase(--s.end());
            //cout << p.second << endl;
            if(p.first < k) {
                break;
            }
            ++res;
            int v = p.second;
            int am = p.first;
            for(int i = 0; i < k; i++) {
                int u = *(g1[v].begin());
                g[v].erase(g[v].find(u));
                g[u].erase(g[u].find(v));
                g1[v].erase(g1[v].begin());
            }
            if(am > k) {
                s.insert({am - k, v});
            }
            if(g[v].size() == 1) {
                if(g1[*(g[v].begin())].size() > 0) {
                    s.erase(s.find({g1[*(g[v].begin())].size(), *(g[v].begin())}));
                }
                g1[*(g[v].begin())].insert(v);
                
                s.insert({g1[*(g[v].begin())].size(), *(g[v].begin())});
            }
        }
        cout << res << '\n';
    }
}