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
int n,k,m,a[100005],ans=0,b[100005];
string s[100005];   
map<string,int> mp;
void solve(){
    cin>>n>>k>>m;
    rep(i,0,n){
        cin>>s[i];
        mp[s[i]]=i;
    }
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,k){
        int x,cos=hell;
        cin>>x;
        vi v;
        rep(j,0,x){
            int y;
            cin>>y;
            y--;
            v.pb(y);
            cos=min(cos,a[y]);
        }
        for(auto j:v){
            b[j]=cos;
        }
    }
    rep(i,0,m){
        string h;
        cin>>h;
        ans+=b[mp[h]];
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