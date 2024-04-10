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
int n,val[200005],v[200005];
ll ans[200005];
vi a[200005];
unordered_map<int,int> mp[200005];
void dfs(int node){
    v[node]=1;
    mp[node][val[node]]++;
    ans[val[node]]++;
    vi g;
    for(auto i:a[node]){
        if(!v[i]){
            g.pb(i);
            dfs(i);
            for(auto j:mp[i]){
                for(auto k:mp[node]){
                    ans[__gcd(j.x,k.x)]+=1LL*j.y*k.y;
                }
            }
            for(auto j:mp[i]){
                mp[node][__gcd(j.x,val[node])]+=j.y;
            }
        }
    }
    for(auto i:g){
        mp[i].clear();
    }
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>val[i];
    }
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1);
    rep(i,1,200001){
        if(ans[i]){
            cout<<i<<" "<<ans[i]<<endl;
        }
    }
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