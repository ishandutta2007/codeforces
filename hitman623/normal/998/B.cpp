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
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,b,a[101],dp[101][101];
int sol(int in,int b){
    if(b<0) return -hell;
    if(dp[in][b]!=-1) return dp[in][b];
    int ans=-hell,o=0,e=0;
    for(int i=in-1;i>0;i--){
        if(a[i+1]%2) o++;
        else e++;
        if(o!=e) continue;
        ans=max(ans,1+sol(i,b-abs(a[i]-a[i+1])));
    }
    if(a[1]%2) o++;
    else e++;
    if(o==e){
        ans=max(ans,0);
    }
    return dp[in][b]=ans;
}
void solve(){
    cin>>n>>b;
    rep(i,1,n+1){
        cin>>a[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<sol(n,b)<<endl;
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