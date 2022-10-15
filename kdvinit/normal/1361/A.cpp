/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 1;

vector<int> adj[N];
int col[N], cur[N], n, m;
int ans[N];

bool check(int i)
{
    int x=col[i],mx=0;
    set<int> dist;
    for(auto y:adj[i])
    {
        if(cur[y]!=-1) { dist.insert(cur[y]); mx=max(mx,cur[y]); }
        //cout<<y<<" "<<cur[y]<<endl;
    }
    int y=dist.size();
    if(y==x-1 && mx==x-1) return true;
    else return false;
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++) adj[i].clear();

    for(int i=1;i<=m;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    pair<int,int> color[n+1];
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x; y=i;
        col[i]=x;
        color[i]={x,y};
    }
    sort(color+1,color+n+1);

    for(int i=1;i<=n;i++) ans[i]=color[i].second;
    for(int i=1;i<=n;i++) cur[i]=-1;

    for(int i=1;i<=n;i++)
    {
        cur[ans[i]]=col[ans[i]];
        if(check(ans[i])==0) { cout<<-1<<endl; return; }
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}