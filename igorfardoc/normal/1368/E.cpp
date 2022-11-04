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
        int n, m;
        cin >> n >> m;
        vvi g(n);
        for(int i = 0; i < m; i++) {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[u].push_back(v);
        }
        vi type1(n);
        type1[0] = 0;
        vi ans;
        for(int i = 1; i < n; i++) {
            set<int> s;
            for(int u : g[i]) {
                s.insert(type1[u]);
            }
            if(s.find(1) != s.end()) {
                ans.push_back(i);
                type1[i] = 2;
            } else if(s.find(0) != s.end()) {
                type1[i] = 1;
            } else {
                type1[i] = 0;
            }
        }
        cout << ans.size() << '\n';
        for(int u : ans) {
            cout << u + 1 << ' ';
        }
        cout << '\n';
    }
}