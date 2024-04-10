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
mi mp;
mii mp2;
int ans,n,a,b,x[200005],vx[200005],vy[200005];
void solve(){
    cin>>n>>a>>b;
    rep(i,0,n){
        cin>>x[i]>>vx[i]>>vy[i];
        mp[vy[i]-a*vx[i]]++;
        mp2[{vx[i],vy[i]}]++;
    }
    for(auto i:mp){
        ans+=i.y*(i.y-1);
    }
    for(auto i:mp2){
        ans-=i.y*(i.y-1);
    }
    cout<<ans<<endl;
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