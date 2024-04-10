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
int k,q;
long double dp[9002][1002];
double sol(int d,int g){
    if(d<0) return 0;
    if(d<g) return dp[d][g]=0;
    if(g==0) return dp[d][g]=1;
    if(dp[d][g]>-1) return dp[d][g];
    dp[d][g]=(g*sol(d-1,g-1)+(k-g)*sol(d-1,g))/k;
    return dp[d][g];
}
void solve(){
    cin>>k>>q;
    rep(i,0,9002){
        rep(j,0,1002){
            dp[i][j]=-1;
        }
    }
    rep(i,1,9000){
        sol(i,k);
    }
    while(q--){
        int p;
        cin>>p;
        rep(i,1,9000){
            if(dp[i][k]*2000+1e-7>=p){
                cout<<i<<endl;
                break;
            }
        }
    }
}

signed main(){
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}