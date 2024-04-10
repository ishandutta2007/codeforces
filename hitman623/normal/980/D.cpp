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
int n,h[5005],dp[5005][5005],ans[5005],a[5005],p[5005];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        h[i]=1e9;
        rep(j,i+1,n){
            int d=a[i]*a[j];
            if(d<=0) continue;
            int w=sqrt(d);
            if(w*w==d){
                h[i]=min(h[i],j);
            }
        }
    }
    p[0]=abs(a[0]);
    rep(i,1,n){
        p[i]=p[i-1]+abs(a[i]);
    }
    rep(i,1,n+1){
        rep(j,0,n-i+1){
            if(i==1){
                dp[j][j+i-1]=1;
            }
            else{
                if(a[j]==0 || h[j]<=j+i-1){
                    dp[j][j+i-1]=dp[j+1][j+i-1];
                }
                else{
                    if(p[j+i-1]-p[j]==0){
                        dp[j][j+i-1]=dp[j+1][j+i-1];
                    }
                    else{
                        dp[j][j+i-1]=1+dp[j+1][j+i-1];
                    }
                }
            }
        }
    }
    rep(i,0,n){
        rep(j,i,n){
            ans[dp[i][j]]++;
        }
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