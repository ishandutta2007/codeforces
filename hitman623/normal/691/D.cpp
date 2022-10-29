#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
struct DSU{
    int N,components;
    vi par,s;
    DSU(int n){
        N=n;
        components=n;
        par.resize(N+1);
        s.resize(N+1);
        s.assign(N+1,1);
        iota(all(par),0);
    }
    int find_par(int node){
        if(node==par[node]) return node;
        else return par[node]=find_par(par[node]);
    }
    void merge(int u,int v){
        u=find_par(u);
        v=find_par(v);
        if(u==v) return;
        if(s[u]<s[v]) swap(u,v);
        par[v]=u;
        s[u]+=s[v];
        s[v]=0;
        components--;
    }
};
int n,m,p[1000006],ans[1000006];
vi v[1000006];
void solve(){
    cin>>n>>m;
    rep(i,1,n+1) cin>>p[i];
    DSU obj(n);
    while(m--){
        int x,y;
        cin>>x>>y;
        obj.merge(x,y);
    }
    rep(i,1,n+1){
        v[obj.find_par(i)].pb(i);
    }
    rep(i,1,n+1){
        vi w;
        for(auto j:v[i]){
            w.pb(p[j]);
        }
        sort(all(v[i]));
        sort(all(w));
        reverse(all(w));
        rep(j,0,sz(w)){
            ans[v[i][j]]=w[j];
        }
    }
    rep(i,1,n+1) cout<<ans[i]<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}