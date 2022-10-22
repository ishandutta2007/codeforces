#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=2e5+10;

int ct,sct;
int o[mn],l[mn],scc[mn];
bool vis[mn],ins[mn];

ll bas[mn];

vi g[mn],d[mn],rg[mn],rd[mn],scgr[mn];


stack<int> st;
void dfs1(int x){
    vis[x]=ins[x]=1;
    st.push(x);
    o[x]=l[x]=ct++;
    for(int y:g[x]){
        if(!vis[y])dfs1(y),l[x]=min(l[x],l[y]);
        else if(ins[y])l[x]=min(l[x],o[y]);
    }
    if(o[x]==l[x]){
        while(st.top()!=x)ins[st.top()]=0,scc[st.top()]=sct,st.pop();
        ins[st.top()]=0,scc[st.top()]=sct,st.pop();
        sct++;
    }
}

ll rdis[mn],dis[mn];
void dfs2(int x){
    vis[x]=1;
    for(int i=0;i<rg[x].size();i++){
        int y=rg[x][i];
        if(vis[y]||scc[x]!=scc[y])continue;
        rdis[y]=rdis[x]+rd[x][i];
        dfs2(y);
    }
}

void dfs3(int x){
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(vis[y]||scc[x]!=scc[y])continue;
        dis[y]=dis[x]+d[x][i];
        dfs3(y);
    }
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(b);
        d[a].push_back(c);
        rg[b].push_back(a);
        rd[b].push_back(c);
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs1(i);
    for(int i=1;i<=n;i++)scgr[scc[i]].push_back(i);
    memset(vis,0,sizeof(vis));
    for(int i=0;i<sct;i++){
        dfs2(scgr[i][0]);
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<sct;i++){
        for(int x:scgr[i])dfs3(x);
        for(int x:scgr[i])bas[i]=__gcd(bas[i],dis[x]+rdis[x]);
    }
    for(int x=1;x<=n;x++)for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(scc[x]!=scc[y])continue;
        int s=scc[x];
        bas[s]=__gcd(bas[s],dis[x]+d[x][i]+rdis[y]);
    }
    int nq;
    cin>>nq;
    while(nq--){
        ll v,s,t;
        cin>>v>>s>>t;
        s=__gcd(s,t);
        ll bes=__gcd(bas[scc[v]],t);
        if(s%bes==0)printf("YES\n");
        else printf("NO\n");
    }
}