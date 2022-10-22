#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
vector<int>g[20];
bool vis[20];
void dfs(int x){
    vis[x]=1;
    for(int y:g[x])if(!vis[y]){
        dfs(y);
    }
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        string s,t;
        cin>>n>>s>>t;
        bool ded=0;
        for(int i=0;i<n;i++)if(s[i]>t[i])ded=1;
        if(ded){
            printf("-1\n");
            continue;
        }
        for(int i=0;i<20;i++)g[i].clear();
        for(int i=0;i<n;i++)if(s[i]<t[i]){
            g[s[i]-'a'].push_back(t[i]-'a');
            g[t[i]-'a'].push_back(s[i]-'a');
        }
        memset(vis,0,sizeof(vis));
        int ans=20;
        for(int i=0;i<20;i++)if(!vis[i])dfs(i),ans--;
        printf("%d\n",ans);
    }
}