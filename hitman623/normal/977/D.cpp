#include <bits/stdc++.h>

#define int          long long
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
int n,a[105];
vector<pair<pii,int>> v;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        int cur=a[i],cn2=0,cn3=0;
        while(cur%2==0) cn2++,cur/=2;
        while(cur%3==0) cn3++,cur/=3;
        v.pb({{cn2,-cn3},i});
    }
    sort(all(v));
    rep(i,0,n){
        cout<<a[v[i].y]<<" ";
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