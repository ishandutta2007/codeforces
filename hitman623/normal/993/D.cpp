#include <bits/stdc++.h>
#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[101],b[101];
int c[101],dp[101][101][101];
vii v;
int sol(int in,int rem,int sim){
    if(in==n) return 0;
    if(dp[in][rem][sim]<1e13) return dp[in][rem][sim];
    int ans=1e13;
    if(in<n-1 and v[in].x==v[in+1].x) ans=min(ans,sol(in+1,rem,sim+1)+c[in]);
    else ans=min(ans,sol(in+1,rem+sim+1,0)+c[in]);
    if(rem){
        if(in<n-1 and v[in].x==v[in+1].x) ans=min(ans,sol(in+1,rem-1,sim));
        else ans=min(ans,sol(in+1,rem-1+sim,0));
    }
    return dp[in][rem][sim]=ans;
}
bool check(int mid){
    rep(i,0,n){
        c[i]=v[i].x-mid*v[i].y;
    }
    memset(dp,127,sizeof dp);
    return sol(0,0,0)<=0;
}
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        a[i]*=1000;
    }
    rep(i,0,n){
        cin>>b[i];
        v.pb({a[i],b[i]});
    }
    sort(all(v));
    reverse(all(v));
    int lo=0,hi=1e12;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    if(check(lo)) cout<<lo<<endl;
    else cout<<hi<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}