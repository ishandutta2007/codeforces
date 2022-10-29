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
int n,k,a[100005],l=-1,r;
void solve(){
    cin>>n>>k;
    r=n;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        if(a[i]>k) break;
        l=i;
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]>k) break;
        r=i;
    }
    cout<<min(n,l+1+n-r)<<endl;
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