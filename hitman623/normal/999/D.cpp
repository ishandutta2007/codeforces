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
int n,m,a[200005],ans;
vi f[200005],v;
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
        f[a[i]%m].pb(i);
    }
    int k=n/m;
    rep(i,0,2*m+1){
        int cur=i%m;
        while(sz(f[cur])>k){
            v.pb(f[cur].back());
            f[cur].pop_back();
        }
        while(sz(f[cur])<k and sz(v)){
            int d=v.back();
            v.pop_back();
            ans+=(cur-(a[d]%m)+m)%m;
            a[d]+=(cur-(a[d]%m)+m)%m;
            f[cur].pb(d);
        }
    }
    cout<<ans<<endl;
    rep(i,0,n){
        cout<<a[i]<<" ";
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