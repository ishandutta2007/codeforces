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
int n,l,w,ans;
vi L,R;
void solve(){
    cin>>n>>l>>w;
    rep(i,0,n){
        int x,v;
        cin>>x>>v;
        if(v>0) R.pb(x);
        else L.pb(x);
    }
    sort(all(R));
    sort(all(L));
    rep(i,0,sz(L)){
        int x2=L[i];
        int r=upper_bound(all(R),x2)-R.begin();
        if(x2+l>0){
            int d=(x2+l)*(w-1)/(w+1);
            int g=upper_bound(R.begin(),R.begin()+r,d)-R.begin();
            while(g and R[g-1]*(w+1)==(x2+l)*(w-1)) g--;
            ans+=g;
        }
        else if(w>1){
            int d=(x2+l)*(w+1)/(w-1);
            if((x2+l)*(w+1)%(w-1)) d--;
            int g=upper_bound(R.begin(),R.begin()+r,d)-R.begin();
            while(g and R[g-1]*(w-1)==(x2+l)*(w+1)) g--;
            ans+=g;
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