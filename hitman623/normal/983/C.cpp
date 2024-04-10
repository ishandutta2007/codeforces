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
// #define int         short int
using namespace std;
int n,a[2002],b[2002];
map<int,int> dp[2001][10];
int go(int id,int cur,vi v){
    if(id==n and sz(v)==0) return 0;
    int hsh=0;
    for(auto i:v){
        hsh=hsh*10+i;
    }
    if(dp[id][cur].count(hsh)){
        return dp[id][cur][hsh];
    }
    int ans=32767;
    if(sz(v)<4 and id<n){
        vi temp=v;
        temp.pb(b[id]);
        sort(all(temp));
        ans=min(1*ans,abs(a[id]-cur)+1+go(id+1,a[id],temp));
    }
    rep(i,0,sz(v)){
        vi temp;
        rep(j,0,sz(v)){
            if(i==j) continue;
            temp.pb(v[j]);
        }
        sort(all(temp));
        ans=min(1*ans,abs(v[i]-cur)+1+go(id,v[i],temp));
    }
    return dp[id][cur][hsh]=ans;
}
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i]>>b[i];
    }
    cout<<go(0,1,{})<<endl;
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