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
int n,k,p[1000006][20],v[1000006]={1};
vi ad[1000006];
void dfs(int node,int par){
    p[node][0]=par;
    for(auto i:ad[node]){
        if(i!=par){
            dfs(i,node);
        }
    }
}
bool check(int node){
    int cnt=1;
    for(int j=19;j>=0;j--){
        if(v[p[node][j]]==0){
            node=p[node][j];
            cnt+=1<<j;
        }
    }
    return cnt<=k;
}
void solve(){
    cin>>n>>k;
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        ad[a].pb(b);
        ad[b].pb(a);
    }
    dfs(n,0);
    k=n-k;
    rep(j,1,20){
        rep(i,1,n+1){
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
    int cur=n;
    while(k){
        if(check(cur)){
            int g=cur;
            while(g and v[g]==0){
                k--;
                v[g]=1;
                g=p[g][0];
            }
        }
        cur--;
        while(v[cur]) cur--;
    }
    rep(i,1,n+1){
        if(!v[i]){
            cout<<i<<" ";
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