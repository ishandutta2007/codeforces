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
int n,x[200005];
mi mp;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>x[i];
        mp[x[i]]=i+1;
    }
    sort(x,x+n);
    rep(i,0,n){
        rep(j,0,33){
            if(mp.count(x[i]+(1LL<<j)) and mp.count(x[i]+(1LL<<j)+(1LL<<j))){
                cout<<3<<endl;
                cout<<x[i]<<" "<<x[i]+(1LL<<j)<<" "<<x[i]+(1LL<<j)+(1LL<<j)<<endl;
                return;
            }
        }
    }
    rep(i,0,n){
        rep(j,0,33){
            if(mp.count(x[i]+(1LL<<j))){
                cout<<2<<endl;
                cout<<x[i]<<" "<<x[i]+(1LL<<j)<<endl;
                return;
            }
        }
    }
    cout<<1<<endl<<x[0]<<endl;
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