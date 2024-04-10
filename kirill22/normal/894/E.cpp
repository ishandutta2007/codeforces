#include <bits/stdc++.h>
using namespace std;
#define int long long
int co = 0,ans = 0;
vector<int> ST_comp,comp,ST,POW(2 * 1e4 + 5, 0),top_sort;
vector<bool> used;
vector<vector<int > > g(1000001),g2(1000001);
vector<vector<pair<int,int>>> g1;
vector<pair<int,int>> R;
void sor(int v){
    used[v] = true;
    for(int i = 0;i < g[v].size();i++){
        int x = g[v][i];
        if(!used[x]){
            sor(x);
        }
    }
    top_sort.push_back(v);
}
void dfs(int v,int k){
    used[v] = true;
    comp[v] = k;
    for(int i = 0;i < g2[v].size();i++){
        int x = g2[v][i];
        if(!used[x]){
            dfs(x,k);
        }
    }
}
vector<int> dp;
void dfs3(int v){
    dp[v] = ST_comp[v];
    for(int i = 0;i < g1[v].size();i++){
        if(dp[g1[v][i].first] == -1){
            dfs3(g1[v][i].first);
        }
        dp[v] = max(dp[v],ST_comp[v] + g1[v][i].second + dp[g1[v][i].first]);
    }

}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1;i < 2 * 1e4 + 5;i++ ){
        POW[i] = POW[i - 1] + (i * (i + 1)) / 2;
    }
    int n,m;
    cin >> n >> m;
    g1.resize(n);
    ST.resize(m);
    comp.resize(n, - 1);
    for(int i = 0;i < m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        x--;
        y--;
        g[x].push_back(y);
        g2[y].push_back(x);
        R.push_back({x,y});
        ST[i] = w;
    }
    used.resize(n,false);
    for(int i = 0;i < n;i++){
        if(!used[i]){
            sor(i);
        }
    }
    reverse(top_sort.begin(),top_sort.end());
    int k = - 1;
    for(int i = 0;i < n;i++){
        used[i] = false;
    }
    for(int i  = 0;i < n;i++){
        if(! used[top_sort[i]]){
            k++;
            dfs(top_sort[i],k);
        }
    }
    int s;
    cin >> s;
    ST_comp.resize(k + 1,0);
    for(int i = 0;i < m;i++){
        if(comp[R[i].first] == comp[R[i].second]){
            int x = 0;
            int y = ST[i] * 2;
            int z = sqrt(y);
            if(z * (z + 1) > y){
                z--;
            }
            x += ST[i] * (z + 1);
            x -= POW[z];
            ST_comp[comp[R[i].first]] += x;
        }
    }
    vector<map<int,int>> a(k + 3);
    for(int i = 0;i < m;i++){
        if(comp[R[i].first] != comp[R[i].second]){
            if(a[comp[R[i].first]].find(comp[R[i].second]) != a[comp[R[i].first]].end()){
                a[comp[R[i].first]][comp[R[i].second]] = max(a[comp[R[i].first]][comp[R[i].second]],ST[i]);
            }
            else{
                a[comp[R[i].first]][comp[R[i].second]] = ST[i];
            }
        }
    }
    for(int i = 0;i <= k + 2;i++){
        for(auto c : a[i]){
            g1[i].push_back({c.first,c.second});
        }
    }
    dp.resize(k + 10, - 1);
    dfs3(comp[s - 1]);
    cout << dp[comp[s - 1]];
}