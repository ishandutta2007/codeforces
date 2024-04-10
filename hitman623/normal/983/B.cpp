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
int n,a[5005],q,dp[5005][5005],f[5005][5005];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        rep(j,1,n+2-i){
            if(i==1){
                f[j][j]=a[j];
            }
            else{
                f[j][j+i-1]=f[j][j+i-2]^f[j+1][j+i-1];    
            }
        }
    }
    for(int i=1;i<=n;i++){
        rep(j,1,n+2-i){
            if(i==1){
                dp[j][j]=a[j];
            }
            else{
                dp[j][j+i-1]=max({dp[j+1][j+i-1],dp[j][j+i-2],f[j][j+i-1]});    
            }
        }
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<dp[l][r]<<endl;
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