#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto qd = [&](int u){
        cout<<"d "<<u+1<<endl;
        int ans;
        cin>>ans;
        return ans;
    };
    auto qs = [&](int u){
        cout<<"s "<<u+1<<endl;
        int ans;
        cin>>ans;
        --ans;
        return ans;
    };
    vector<int> sz(n, 1);
    vector<int> dep(n);
    vector<int> par(n);
    {
        function<void(int,int)> dfs = [&](int u, int p){
            for(int i=0;i<g[u].size();i++){
                if(g[u][i] == p){
                    g[u].erase(g[u].begin() + i);
                    break;
                }
            }
            for(auto &v : g[u]){
                dep[v] = dep[u] + 1;
                par[v] = u;
                dfs(v, u);
                sz[u] += sz[v];
            }
            sort(g[u].begin(), g[u].end(), [&](int x,int y){
                return sz[x] > sz[y];
            });
        };
        dfs(0, -1);
    }
    int d = qd(0);
    int p = 0;
    while(true){
        if(g[p].size() > 0 && sz[g[p][0]] * 2 > sz[p]){
            int chk = p;
            while(g[chk].size() > 0 && sz[g[chk][0]] * 2 > sz[chk]){
                chk = g[chk][0];
            }
            int dst = qd(chk);
            int dfltdst = abs(dep[chk] - d);
            // Know: dst = dep[ans]+dep[chk]-2*dep[LCA]
            // dep[LCA] = (dep[ans]+dep[chk]-dst)/2
            int dLCA = (d+dep[chk]-dst)/2;
            while(dep[chk]>dLCA){
                chk = par[chk];
            }
            p = chk;
        }
        if(dep[p] == d) break;
        p = qs(p);
    }
    cout<<"! "<<p+1<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}