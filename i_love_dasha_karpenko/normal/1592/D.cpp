#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e3+7;
vector<int> G[N];
int vis[N],n;

vector<int> euler;
int ask(int l,int r){
   set<int> V;
   for(int i = l;i<=r;++i)
       V.insert(euler[i]);
   if (V.size()==1)
       return 0;
    cout<<"? "<<V.size()<<' ';
    for(int to:V)
        cout<<to<<' ';
    cout<<endl;
    int ret;
    cin>>ret;
    return ret;
}
void dfs(int v,int par){
    euler.push_back(v);
    for(int to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
        euler.push_back(v);
    }
}
void solve(){
    cin>>n;
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    int need = ask(0,euler.size()-1);
    if (need==0){
        cout<<"1 2\n";
        return;
    }
    int l = 0,r = euler.size()-1;
    while(r-l>1) {
        int tm = (l + r) >> 1;
        if (ask(l, tm) == need)
            r = tm;
        else l = tm;
    }
    if (euler[l]==euler[r]){
        cout<<need<<endl;
        return;
    }
    cout<<"! "<<euler[l]<<' '<<euler[r]<<endl;
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t = 1;
    while(t--)
        solve();
}