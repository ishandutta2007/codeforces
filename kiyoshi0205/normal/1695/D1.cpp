// https://atcoder.jp/contests/apc001/submissions/32135064

#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, u, v, pos = 0;
    cin >> n;
    if(n==1){
      puts("0");
      return;
    }
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(g[u].size() > 2)pos = u;
        if(g[v].size() > 2)pos = v;
    }
    function<pair<int,int>(int,int)> dfs=[&](int v, int p){
        int s1 = 0, s2 = 0;
        for(auto &&u:g[v]){
            if(u == p)continue;
            auto q = dfs(u, v);
            s1 += q.first, s2 |= q.second;
        }
        s1 -= s2;
        return make_pair(max(1, s1), s1 <= 0);
    };
    cout << dfs(pos, -1).first << '\n';
}
int main(){
  int T;
  cin>>T;
  while(T--)solve();
}