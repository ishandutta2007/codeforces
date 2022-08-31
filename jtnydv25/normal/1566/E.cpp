#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> par(n), up(n);
        vector<vector<int>> children(n);
        int k = 0;
        int bad = 0;
        int nonempty;
        function<int(int, int)> dfs = [&](int s, int p){
            int r = 0;
            for(int v : adj[s]) if(v != p){
                r += dfs(v, s);
            }
            if(s != 0){
                if(r > 0){
                    k++;
                    return 0;
                }
                return 1;
            } else nonempty = r != 0;
            return 0;
        };

        dfs(0, -1);
        // trace(empty);
        cout << max(1, n - 2 * k - nonempty) << endl;
    }
}