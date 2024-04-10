#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
void solve(){
    int n,t,tt;cin>>n;
    vector<int>conn[n+5];
    int wei[n+5];
    int deg[n+5];
    memset(deg,0,sizeof deg);
    int ans=0;
    for(int i=1;i<=n;i++)cin>>wei[i],ans+=wei[i];
    for(int i=1;i<n;i++){
        cin>>t>>tt;
        deg[t]++;deg[tt]++;
        conn[t].pb(tt);
        conn[tt].pb(t);
    }
    priority_queue<int>a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<deg[i];j++)a.push(wei[i]);
    }
    cout<<ans<<" ";
    for(int i=2;i<n;i++){
        ans+=a.top();
        cout<<ans<<" ";
        a.pop();
    }
    cout<<endl;
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}