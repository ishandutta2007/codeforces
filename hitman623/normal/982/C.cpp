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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,s[100005],ans;
vi ad[100005];
void dfs(int node){
    s[node]=1;
    for(auto i:ad[node]){
        if(!s[i]){
            dfs(i);
            s[node]+=s[i];
        }
    }
    if(s[node]%2==0) ans++;
}
void solve(){
    cin>>n;
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        ad[u].pb(v);
        ad[v].pb(u);
    }
    if(n%2){
        cout<<-1<<endl;
        return;
    }
    dfs(1);
    cout<<ans-1<<endl;
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