/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    char a[n+2][m+2];
    int b[n+2][m+2], vis[n+2][m+2];
    int lx, ly;

    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=m+1; j++)
        {
            if(i==0 || i==n+1 || j==0 || j==m+1) a[i][j]='#';
            else cin>>a[i][j];
            b[i][j]=0;  vis[i][j]=0;
            if(a[i][j]=='L') { lx=i; ly=j; }
        }
    }

    int dx[4]={0, 0, 1, -1};
    int dy[4]={-1, 1, 0, 0};

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]=='#') continue;
            int cnt=0;
            for(int k=0; k<4; k++)
            {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(a[nx][ny]=='#') cnt++;
            }
            if(cnt>=2) b[i][j]=1;
        }
    }

    stack<pair<int, int>> dfs;
    dfs.push({lx, ly});
    vis[lx][ly]=1;

    while(!dfs.empty())
    {
        auto cur = dfs.top();
        dfs.pop();
        int i=cur.first;
        int j=cur.second;
        for(int k=0; k<4; k++)
        {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(b[nx][ny]==0 || vis[nx][ny]) continue;
            vis[nx][ny]=1;
            dfs.push({nx, ny});
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]!='.' || vis[i][j]==1) continue;
            stack<pair<int, int>> bfs;
            bfs.push({i, j});
            while(!bfs.empty())
            {
                auto cur = bfs.top();
                bfs.pop();
                int x=cur.first;
                int y=cur.second;

                int ex, ey;
                int nopos=0, pos=0;

                for(int k=0; k<4; k++)
                {
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if(a[nx][ny]=='.' && vis[nx][ny]==0) { nopos++; ex=nx; ey=ny; }
                    if(a[nx][ny]=='L' || vis[nx][ny]==1) pos=1;
                }

                if(pos==0 || nopos>1) continue;
                vis[x][y]=1;
                if(nopos==1) bfs.push({ex, ey});
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]=='.' && vis[i][j]==1) cout<<'+';
            else cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}