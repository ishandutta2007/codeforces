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
int n,m,K,dp[505][505],dp2[505][505];  
string a[505];
void solve(){
    cin>>n>>m>>K;
    rep(i,0,503){
        rep(j,0,503){
            dp[i][j]=hell;
            dp2[i][j]=hell;
        }
    }
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        int tot=0;
        rep(j,0,m){
            tot+=a[i][j]-'0';
        }
        rep(j,0,m){
            int cur=0;
            rep(k,j,m){
                if(a[i][j]!='1' || a[i][k]!='1') continue;
                if(a[i][k]=='1') cur++;
                dp[i][tot-cur]=min(dp[i][tot-cur],k-j+1);
            }
        }
        dp[i][tot]=0;
        rep(j,1,K+1){
            dp[i][j]=min(dp[i][j-1],dp[i][j]);
        }
        if(i==0){
            rep(j,0,K+1){
                dp2[i][j]=dp[i][j];
            }
        }
        else{
            rep(j,0,K+1){
                rep(k,0,j+1){
                    dp2[i][j]=min(dp2[i][j],dp2[i-1][j-k]+dp[i][k]);
                }
            }            
        }
    }
    cout<<dp2[n-1][K];
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