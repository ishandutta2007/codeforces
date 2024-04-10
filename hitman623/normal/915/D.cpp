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
vi a[505],p;
int v[505],c[505],f,mark[505][505];
stack<int> path;
void dfs(int node){
    path.push(node);
    v[node]=1;
    c[node]=1;
    for(auto i:a[node]){
        if(!f){
            if(v[i] && c[i]){
                f=1;
                p.pb(i);
                while(!path.empty() && path.top()!=i){
                    p.pb(path.top());
                    path.pop();
                }
                p.pb(i);
                reverse(all(p));
            }
            else if(!v[i]) dfs(i);
        }
    }
    if(!f)
    path.pop(),c[node]=0;
}
void check(int node){
    v[node]=1;
    c[node]=1;
    for(auto i:a[node]){
        if(mark[node][i]) continue;
        if(!v[i]) check(i);
        else if(c[i]) f=1;
    }
    c[node]=0;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
    }
    rep(i,1,n+1)
    if(!v[i] && !f){
        memset(c,0,sizeof c);
        dfs(i);
    }
    if(sz(p)==0) {cout<<"YES";return;}
    rep(i,0,sz(p)-1){
        mark[p[i]][p[i+1]]=1;
        memset(v,0,sizeof v);
        f=0;
        rep(j,1,n+1){
            if(v[j]==1) continue;
            memset(c,0,sizeof c);
            check(j);
            if(f) break;
        }
        if(!f){
            cout<<"YES";
            return;
        }
        mark[p[i]][p[i+1]]=0;
    }
    cout<<"NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
        solve();
    return 0;
}