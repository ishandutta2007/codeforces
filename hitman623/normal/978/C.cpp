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
int n,m,a[200005],b[200005],p[200005];
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
        p[i]=a[i]+(i?p[i-1]:0);
    }
    rep(i,0,m){
        cin>>b[i];
        int l=lower_bound(p,p+n,b[i])-p;
        cout<<l+1<<" "<<b[i]-(l?p[l-1]:0)<<endl;
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