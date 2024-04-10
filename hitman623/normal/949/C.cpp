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
mii mp,ed;
vi a[100005],b[100005],ans[100005];
int vis[100005],visInv[100005],scc[100005],n,m,h,val[100005],counter=1;
stack<int> s;
void dfsFirst(int u){
    if(vis[u])
        return;
    vis[u]=1;
    for(auto i:a[u])
        dfsFirst(i);
    s.push(u);
}
void dfsSecond(int u){
    if(visInv[u])
        return;
    visInv[u]=1;
    for(auto i:b[u])
        dfsSecond(i);
    scc[u]=counter;
    ans[counter].pb(u);
}

int main(){
    cin>>n>>m>>h;
    rep(i,1,n+1){
        cin>>val[i];
    }
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        if(mp[{x,y}]) continue;
        mp[{x,y}]=1;
        mp[{y,x}]=1;
        if(val[y]==(h+val[x]-1)%h){
            a[y].pb(x);
            b[x].pb(y);
            ed[{y,x}]=1;
        }
        if(val[x]==(h+val[y]-1)%h){
            a[x].pb(y);
            b[y].pb(x);
            ed[{x,y}]=1;
        }
    }
    rep(i,1,n+1){
        if(!vis[i]){
            dfsFirst(i);
        }
    } 
    while (!s.empty()){
        int d=s.top();
        s.pop();
        if (!visInv[d]){
            dfsSecond(d);
            counter++;
        }
    }
    vi ansvec;
    rep(i,1,n+1){
        vis[i]=1;
    }
    for(auto i:ed){
        if(scc[i.x.x]!=scc[i.x.y]){
            vis[scc[i.x.x]]=0;
        }
    }
    rep(i,1,counter){
        if(!vis[i]) continue;
        if(sz(ans[i])<sz(ansvec) || !sz(ansvec)) ansvec=ans[i];
    }
    cout<<sz(ansvec)<<endl;
    for(auto i:ansvec){
        if(i<=n) cout<<i<<" ";
    }
    return 0;
}