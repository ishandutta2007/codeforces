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
int n,k,p[100005],c[100005],ans[100005];
vector<pair<int,pii>> v;
vi s;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>p[i];
    }
    rep(i,0,n){
        cin>>c[i];
        v.pb({p[i],{c[i],i}});
    }
    sort(all(v));
    s.resize(k);
    rep(i,0,n){
        int res=v[i].y.x;
        rep(j,0,min(i,k)){
            res+=s[j];
        }
        ans[v[i].y.y]=res;
        s.pb(v[i].y.x);
        sort(all(s));
        reverse(all(s));
        s.resize(k);
    }
    rep(i,0,n){
        cout<<ans[i]<<" ";
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