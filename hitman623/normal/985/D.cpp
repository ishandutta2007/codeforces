#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          unordered_map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,h,ans=LLONG_MAX;
int f(int r,int x){
    int d=(r+1)*(2*x+r)+(x+r-1)*(x+r);
    if(x>h || x<0 || d>2*n || r<0 || x+r<=0) return LLONG_MAX;
    int h=n-d/2;
    return 2*r+x+h/(x+r)+(!!(h%(x+r)));    
}
void solve(){
    cin>>n>>h;
    int d=(sqrt(8*n-1)+1)/2;
    d=min(d,h);
    rep(x,d-1,d+2){
        int y=sqrt((2*n+x*x-x)/2)-x;
        rep(r,y-1,y+2){
            ans=min(ans,f(r,x));
        }
    }
    cout<<ans<<endl;
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