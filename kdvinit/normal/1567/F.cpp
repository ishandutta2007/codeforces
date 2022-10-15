/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 505;

int a[N][N];
int cnt[N][N];
int vis[N][N];
int val[N][N];
int ans[N][N];

vector<int> adjx[N][N];
vector<int> adjy[N][N];
int n, m;

void BFS(int x1, int y1)
{
    queue<int> qx, qy, dep;
    qx.push(x1); qy.push(y1); dep.push(1);


    while(!qx.empty())
    {
        int i = qx.front(); qx.pop();
        int j = qy.front(); qy.pop();
        int d = dep.front();    dep.pop();

        if(d%2==1) val[i][j]=1;
        else val[i][j]=4;

        int l = adjx[i][j].size();
        for(int k=0; k<l; k++)
        {
            int ni = adjx[i][j][k];
            int nj = adjy[i][j][k];
            if(a[ni][nj]==0 || vis[ni][nj]==1) continue;
            vis[ni][nj]=1;
            qx.push(ni);    qy.push(nj); dep.push(d+1);
        }
    }
}

void add_adj(int x1, int y1, int x2, int y2)
{
    adjx[x1][y1].push_back(x2); adjy[x1][y1].push_back(y2);
    adjx[x2][y2].push_back(x1); adjy[x2][y2].push_back(y1);
}

void check(int x1, int y1, int x2, int y2)
{
    if((a[x1][y1]+a[x2][y2]==2))  add_adj(x1, y1, x2, y2);
}

void solve()
{
    cin>>n>>m;
    for(int i=0; i<=n+1; i++) for(int j=0; j<=m+1; j++) a[i][j]=0, vis[i][j]=0, val[i][j]=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            if(x=='.') a[i][j]=1;
        }
    }

    int pos=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cnt[i][j]=0;
            if(a[i][j]==1) continue;
            cnt[i][j]=(a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1]);
            if(cnt[i][j]%2) pos=0;
        }
    }

    if(!pos) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(cnt[i][j]==0) continue;
            if(cnt[i][j]==4)
            {
                add_adj(i-1, j, i, j-1);
                add_adj(i-1, j, i, j+1);
                add_adj(i+1, j, i, j-1);
                add_adj(i+1, j, i, j+1);
            }
            if(cnt[i][j]==2)
            {
                check(i-1, j, i, j-1);
                check(i-1, j, i, j+1);
                check(i+1, j, i, j-1);
                check(i+1, j, i, j+1);
                check(i-1, j, i+1, j);
                check(i, j-1, i, j+1);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==0 || vis[i][j]==1) continue;
            BFS(i, j);
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==1) ans[i][j]=val[i][j];
            else ans[i][j]=(val[i-1][j]+val[i+1][j]+val[i][j-1]+val[i][j+1]);
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}