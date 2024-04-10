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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,x,y,v[300005],s[300005];
vi ad[300005];
int dfs(int node){
    v[node]=1;
    s[node]=1;
    int f=node==y;
    for(auto i:ad[node]){
        if(!v[i]){
            if(!dfs(i)){
                s[node]+=s[i];
            }
            else{
                f=1;
            }
        }
    }
    return f;
}
void solve(){
    cin>>n>>x>>y;
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        ad[a].pb(b);
        ad[b].pb(a);
    }
    dfs(x);
    cout<<n*(n-1)-s[x]*s[y]<<endl;
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