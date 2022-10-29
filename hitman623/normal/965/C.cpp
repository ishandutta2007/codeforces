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
int n,k,m,d,ans;

// int g=n/x;
// ((g+k-1)/k)*x
// (g+k-1)/k = d
//  d*k-k+1 <= n/x <= d*k
//  (d*k-k+1)*x <= n <= d*k*x+x-1
// 
//  n/x <= d*k

//  n <= d*k*x+x-1

// (n+1+d*k)/(d*k+1) <= x

// 

void solve(){
    cin>>n>>k>>m>>d;
    rep(w,1,d+1){
        if(w-1>n/k) continue;
        int x=min(m,(n/(w*k-k+1)));
        if(x-1>=n/(w*k+1)){
            ans=max(ans,w*x);
        }
    }
    cout<<ans<<endl;
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