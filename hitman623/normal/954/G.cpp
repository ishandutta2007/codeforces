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
int n,r,k,a[2000005];
int b[2000005];
bool check(int mid){
    int cur=0,cnt=0;
    rep(i,0,n+2*r){
        b[i]=a[i];
    }
    rep(i,0,2*r){
        cur+=b[i];
    }
    rep(i,2*r,n+2*r){
        cur+=b[i];
        if(cur<mid){
            b[i]+=mid-cur;
            cnt+=mid-cur;
            cur=mid;
        }
        if(cnt>k) break;
        cur-=b[i-2*r];
    }
    return cnt<=k;
}
void solve(){
    cin>>n>>r>>k;
    rep(i,r,n+r){
        cin>>a[i];
    }
    int lo=0,hi=2e18;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) lo=mid;
        else hi=mid;
    }
    if(check(hi))
    cout<<hi<<endl;
    else if(check(lo)) cout<<lo<<endl;
    else assert(false);
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