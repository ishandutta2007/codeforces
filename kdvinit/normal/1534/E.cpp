/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 501;
int vis[N]={0};
int par[N];
vector<int> adj[N];
int dist[N];

void BFS(int chi)
{
    queue<int> qu;
    vis[chi]=1;
    dist[chi]=0;
    qu.push(chi);

    while(!qu.empty())
    {
        int cur = qu.front();
        qu.pop();
        for(auto x: adj[cur])
        {
            if(vis[x]==1) continue;
            vis[x]=1;
            par[x]=cur;
            qu.push(x);
        }
    }
}

void solve()
{
    int n, k;
    cin>>n>>k;

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j>k) continue;
            int x = i-j+(k-j);
            int y = i+(k-j);
            if(y>n) continue;
            adj[i].push_back(x);
        }
    }

    BFS(0);
    if(vis[n]==0) { cout<<-1<<endl; return; }

    int cur = n;
    vector<int> take;

    while(1)
    {
        if(cur==0) break;
        int p = par[cur];
        int x = (k-(cur-p))/2;
        take.push_back(x);
        cur=p;
    }
    reverse(take.begin(), take.end());

    int ans=0, tmp;

    int par[n+1]={0};

    int d = take.size(), p1, p0;
    for(int i=0; i<d; i++)
    {
        p1 = take[i];
        p0 = k-p1;
        cout<<"? ";

        for(int i=1; i<=n; i++)
        {
            if(par[i]==0)
            {
                if(p0==0) continue;
                p0--;
                par[i]=1;
                cout<<i<<" ";
            }
            else
            {
                if(p1==0) continue;
                p1--;
                par[i]=0;
                cout<<i<<" ";
            }
        }
        cout<<endl;
        cin>>tmp;
        ans^=tmp;
    }
    cout<<"! ";
    cout<<ans<<endl;

}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}