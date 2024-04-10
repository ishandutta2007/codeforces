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
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k;
double dp[1<<20]={1},p[22],ans[22];
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>p[i];
    }
    rep(i,0,1<<n){
        int d=__builtin_popcount(i);
        if(d>k) continue;
        double sp=0;
        rep(j,0,n){
            if(!((i>>j)&1)){
                sp+=p[j];
            }
        }
        rep(j,0,n){
            if((i>>j)&1){
                if(p[j]>0.0000001){
                    dp[i]+=dp[i^(1<<j)]*p[j]/(sp+p[j]);
                    ans[j]+=dp[i^(1<<j)]*p[j]/(sp+p[j]);
                }
            }
        }
    }
    rep(i,0,n){
        cout<<fixed<<setprecision(10)<<ans[i]<<" ";
    }
    cout<<endl;
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