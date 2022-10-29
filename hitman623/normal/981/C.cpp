#include <bits/stdc++.h>

#define int         long long
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
#define N           100000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,v[100005],d,mx=1,in[100005];
vi a[100006],p;
void dfs(int node){
    int f=0;
    v[node]=1;
    for(auto i:a[node]){
        if(i!=mx and !v[i]){
            f=1;
            dfs(i);
        }
    }
    if(!f) d=node;
}
void solve(){
    cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        in[x]++;
        in[y]++;
    }
    rep(i,1,n+1){
        if(in[i]>in[mx]) mx=i;
    }
    for(auto i:a[mx]){
        in[i]--;
    }
    rep(i,1,n+1){
        if(i==mx) continue;
        if(in[i]>2){cout<<"No";return;}
    }
    for(auto i:a[mx]){
        if(in[i]>1) {cout<<"No";return;}
    }
    cout<<"Yes"<<endl;
    for(auto i:a[mx]){
        dfs(i);
        p.pb(d);
    }
    cout<<sz(p)<<endl;
    for(auto i:p){
        cout<<mx<<" "<<i<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}