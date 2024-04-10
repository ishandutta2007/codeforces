#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<int,pii>    
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,in[100005],l[100005],b[100005],v[100005];
vi a[100005],ans;
void dfs(int node,int par){
    if(par!=-1){
        l[node]=l[par]+1;
        if(b[node]!=par && b[par]!=b[node] && b[node]!=node) {cout<<-1;exit(0);}
    }
    else l[node]=1;
    for(auto i:a[node]){
        dfs(i,node);
    }
    if(v[b[node]]==0) {ans.pb(b[node]),v[b[node]]=1;}
}
void solve()
{
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        in[y]++;
    }
    rep(i,1,n+1){
        cin>>b[i];
    }
    rep(i,1,n+1){
        if(in[i]==0) dfs(i,-1);
    }
    cout<<ans.size()<<endl;
    sort(all(ans),[](int a,int b){
        return l[a]>l[b];
    });
    for(auto i:ans){
        cout<<i<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}