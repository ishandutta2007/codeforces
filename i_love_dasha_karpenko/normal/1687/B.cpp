#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
const int M = 500+7;
ll ask(vector<int> &vis){
    cout<<"? ";
    for(auto to:vis){
        cout<<to;
    }
    cout<<endl;
    ll ret;
    cin>>ret;
    return ret;
}
pair<int,int> W[M];
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> vis(m,0);
    for(int i = 0;i<m;i+=1){
        vis[i] = 1;
        W[i].first = ask(vis);
        W[i].second = i;
        vis[i] = 0;
    }
    sort(W,W+m);
    ll rv = 0;
    for(int i = 0;i<m;i+=1){
        vis[W[i].second] = 1;
        ll nv = ask(vis);
        if (nv!=rv+W[i].first){
            vis[W[i].second] = 0;
        }
        else{
            rv = nv;
        }
    }
    cout<<"! "<<rv<<endl;
}
signed main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}