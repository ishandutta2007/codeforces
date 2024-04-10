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
int k,pa,pb,invb,invapb,dp[2001][2001];
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
int sol(int a,int ab){
    if(dp[a][ab]!=-1) return dp[a][ab];
    if(a+ab>=k){
        return dp[a][ab]=(a+ab+pa*invb)%hell;
    }
    dp[a][ab]=(pa*sol(a+1,ab)+pb*sol(a,ab+a))%hell;
    dp[a][ab]=(dp[a][ab]*invapb)%hell;
    return dp[a][ab];
}
void solve(){
    memset(dp,-1,sizeof dp);
    cin>>k>>pa>>pb;
    invb=expo(pb,hell-2,hell);
    invapb=expo(pa+pb,hell-2,hell);
    cout<<sol(1,0)<<endl;
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