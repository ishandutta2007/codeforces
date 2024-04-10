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
int x,y,l,r,ans;
vi v;
void solve(){
    cin>>l>>r>>x>>y;
    if(y%x){
        cout<<0<<endl;
        return;
    }
    y/=x;
    for(int i=1;i*i<=y;++i){
        if(y%i==0){
            v.pb(i);
            if(i*i!=y){
                v.pb(y/i);
            }
        }
    }
    for(auto i:v){
        int a=x*i,b=x*y/i;
        if(l<=a and a<=r and l<=b and b<=r and __gcd(a,b)==x){
            ans++;
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