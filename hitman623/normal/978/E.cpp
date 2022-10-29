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
int n,w,a[1005],mx=LLONG_MIN,mn=LLONG_MAX;
void solve(){
    cin>>n>>w;
    rep(i,0,n){
        cin>>a[i];
        if(i) a[i]+=a[i-1];
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    int l=max(0LL,-mn),r=min(w,(w-mx));
    cout<<max(0LL,r-l+1)<<endl;
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