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
int n,k,h[11],dp[505][5005],ans;
mi f,c;
void solve(){
    cin>>n>>k;
    rep(i,0,n*k){
        int x;
        cin>>x;
        c[x]++;
    }
    rep(i,0,n){
        int x;
        cin>>x;
        f[x]++;
    }
    rep(i,1,k+1){
        cin>>h[i];
    }
    rep(i,1,n+1){
        rep(j,0,n*k+1){
            rep(l,0,min(j,k)+1){
                dp[i][j]=max(dp[i][j],dp[i-1][j-l]+h[l]);
            }
        }
    }
    vii v(all(f));
    rep(i,0,sz(v)){
        ans+=dp[v[i].y][c[v[i].x]];
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