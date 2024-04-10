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
#define N           100000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,a[101],cur=0;
int dp[55][55];
bool sol(int n,int k,int cur){
    if(n==-1) return k==0;
    if(k==0) return n==-1;
    if(dp[n][k]!=-1) return dp[n][k];
    int h=0,ans=0;
    for(int i=n;i>=0;i--){
        h+=a[i];
        if((cur&h)==cur){
            ans|=sol(i-1,k-1,cur);
        }
    }
    return dp[n][k]=ans;
}
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
    }
    for(int i=60;i>=0;i--){
        memset(dp,-1,sizeof dp);
        if(sol(n-1,k,cur|(1LL<<i))){
            cur|=1LL<<i;
        }
    }
    cout<<cur<<endl;
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