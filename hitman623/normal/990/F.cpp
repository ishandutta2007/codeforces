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

int n,m,f[200005],s[200005],vis[200005];
vi a[200005];
mii mp;

void dfs(int node){
    vis[node]=1;
    int cur=0;
    for(auto i:a[node]){
        if(!vis[i]){
            dfs(i);
            if(mp[{node,i}]){
                f[mp[{node,i}]]=s[i];
            }
            else{
                f[mp[{i,node}]]=-s[i];
            }
            cur+=s[i];
        }
    }
    s[node]+=cur;
}

void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>s[i];
    }
    cin>>m;
    rep(i,1,m+1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        mp[{x,y}]=i;
    }
    dfs(1);
    if(s[1]!=0){
        cout<<"Impossible"<<endl;
    }
    else{
        cout<<"Possible"<<endl;
        rep(i,1,m+1){
            cout<<f[i]<<endl;
        }
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