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
int n,k,a[200005],ans[200005];
vi b[200005];
map<int,vi> mp;
void solve(){
    cin>>n>>k;
    rep(i,1,n+1){
        cin>>a[i];
        mp[a[i]].pb(i);
    }
    rep(i,0,k){
        int x,y;
        cin>>x>>y;
        b[x].pb(y);
        b[y].pb(x);
    }
    int cur=0;
    for(auto i:mp){
        for(auto j:i.y){
            ans[j]=cur;
            for(auto kk:b[j]){
                if(a[kk]<a[j]) ans[j]--;
            }
        }
        cur+=sz(i.y);
    }
    rep(i,1,n+1){
        cout<<ans[i]<<" ";
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