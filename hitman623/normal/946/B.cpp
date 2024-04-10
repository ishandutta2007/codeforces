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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
void solve(){
    ll n,m;
    cin>>n>>m;
    rep(i,0,100){
        if(n==0 || m==0) break;
        if(n>=2*m) n%=2*m;
        else if(m>=2*n) m%=2*n;
    }
    cout<<n<<" "<<m;
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