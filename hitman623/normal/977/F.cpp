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
int ans=0,in=0; 
int n,a[200005];
map<int,int> dp;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        if(dp.count(a[i]-1)){
            dp[a[i]]=max(dp[a[i]],1+dp[a[i]-1]);
        }
        else{
            dp[a[i]]=max(dp[a[i]],1);
        }
        if(ans<dp[a[i]]){
            ans=dp[a[i]];
            in=a[i]-ans+1;
        }
    }
    cout<<ans<<endl;
    int cur=in;
    rep(i,0,n){
        if(a[i]==cur){
            cout<<i+1<<" ";
            cur++;
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