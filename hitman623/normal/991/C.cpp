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
ll n;
bool check(ll m){
    ll cur=n,cnt=0;
    while(cur){
        cnt+=min(m,cur);
        cur-=min(m,cur);
        cur-=cur/10;
    }
    return 2*cnt>=n;
}
void solve(){
    cin>>n;
    ll lo=1,hi=1e18;
    while(hi-lo>1){
        ll mid=(lo+hi)/2;
        if(check(mid)){
            hi=mid;
        }
        else{
            lo=mid;
        }
    }
    if(hi-1>0 and check(hi-1)) cout<<hi-1<<endl;
    else if(check(hi)) cout<<hi<<endl;
    else cout<<hi+1<<endl;
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