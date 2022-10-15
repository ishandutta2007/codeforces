/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

int a[N][N];
int dist[N][N];
int vis[N][N];
int r, c;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int ei, int ej)
{
    queue<pair<int, int>> qu;
    dist[ei][ej]=0;
    vis[ei][ej]=1;
    qu.push({ei, ej});
    while(!qu.empty())
    {
        auto cur = qu.front(); qu.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<1 || nx>r || ny<1 || ny>c) continue;
            if(vis[nx][ny]==1 || a[nx][ny]==-1) continue;
            dist[nx][ny] = dist[x][y]+1;
            vis[nx][ny]=1;
            qu.push({nx, ny});
        }
    }
}

void solve()
{
    cin>>r>>c;

    int ei, ej, si, sj;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            char x; cin>>x;
            a[i][j] = 0; vis[i][j]=0;
            if(x=='E') { ei = i; ej = j; continue; }
            if(x=='S') { si = i; sj = j; continue; }
            if(x=='T') { a[i][j] = -1; continue; }
            a[i][j] = x-'0';
        }
    }

    BFS(ei, ej);

    int ans = 0;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(vis[i][j]==1 && dist[i][j]<=dist[si][sj]) ans+=a[i][j];
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}