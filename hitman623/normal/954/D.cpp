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
int n,m,s,t,v[1001];
vi a[1001];
int b[1001][1001];
int diss[1001],dist[1001];
void solve(){
    memset(diss,1,sizeof diss);
    memset(dist,1,sizeof dist);
    cin>>n>>m>>s>>t;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        b[x][y]=1;
        b[y][x]=1;
    }
    queue<pii> q;
    q.push({0,s});
    v[s]=1;
    while(!q.empty()){
        auto d=q.front();
        q.pop();
        diss[d.y]=d.x;
        for(auto i:a[d.y]){
            if(!v[i]){
                v[i]=1;
                q.push({d.x+1,i});            
            }
        }
    }
    memset(v,0,sizeof v);
    q.push({0,t});
    v[t]=1;
    while(!q.empty()){
        auto d=q.front();
        q.pop();
        dist[d.y]=d.x;
        for(auto i:a[d.y]){
            if(!v[i]){
                v[i]=1;
                q.push({d.x+1,i});            
            }
        }
    }   
    int ans=0;
    rep(i,1,n+1){
        rep(j,i+1,n+1){
            if(b[i][j]) continue;
            if(diss[i]+dist[j]+1>=dist[s] && dist[i]+diss[j]+1>=dist[s]) ans++; 
        }
    }
    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}