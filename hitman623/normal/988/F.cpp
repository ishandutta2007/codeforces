#include <bits/stdc++.h>

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
int a,n,m,r[2002],dp[2002][2002],p[2002],x[2002];
void solve(){
    memset(dp,127,sizeof dp);
    cin>>a>>n>>m;
    rep(i,0,n){
        int L,R;
        cin>>L>>R;
        rep(j,L,R){
            r[j]=1;
        }
    }
    rep(i,1,m+1){
        cin>>x[i]>>p[i];
    }
    rep(i,0,a+1){
        rep(j,0,m+1){
            if(j==0){
                if(r[i]){
                    dp[i][j]=hell;
                    continue;
                }
                else{
                    if(i==0){
                        dp[i][j]=0;
                    }
                    else{
                        rep(k,0,m+1){
                            dp[i][j]=min(dp[i-1][k],dp[i][j]);
                        }
                    }
                }
            }
            else{
                if(x[j]>i){
                    dp[i][j]=hell;
                    continue;
                }
                if(x[j]==i){
                    if(i==0){
                        dp[i][j]=p[j];
                        continue;
                    }
                    rep(k,0,m+1){
                        dp[i][j]=min(dp[i][j],p[j]+dp[i-1][k]);
                    }
                }
                else{
                    dp[i][j]=(i?dp[i-1][j]:0)+p[j];
                }
            }
        }
    }
    int ans=hell;
    rep(i,0,m+1){
        ans=min(ans,dp[a][i]);
    }
    if(ans<hell){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
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