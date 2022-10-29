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
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n;
map<pair<int,ll>,int> g;
int sol(int x,ll b){
    if(x==0) return 0;
    if(g.count({x,b})) return g[{x,b}];
    vector<bool> r(63,false);
    rep(i,1,x+1){
        if((b>>i)&1LL) continue;
        r[sol(x-i,b|(1LL<<i))]=1;
    }
    rep(i,0,70){
        if(!r[i]) return g[{x,b}]=i;
    }
}
void solve(){
    cin>>n;
    int ans=0;
    rep(i,0,61){
        sol(i,0);
    }
    rep(i,0,n){
        int s;
        cin>>s;
        ans^=g[{s,0}];
    }
    if(!ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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