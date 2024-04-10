/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

map<int, map<int, int>> pos, vis, moves;

int x[2], y[2];
int dx[3] = {-1, 0, 1};
int dy[3] = {-1, 0, 1};

void BFS(int si, int sj)
{
    queue<pair<int, int>> qu;
    moves[si][sj]=0;
    vis[si][sj]=1;
    qu.push({si, sj});
    while(!qu.empty())
    {
        auto cur = qu.front(); qu.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                int nx = x+dx[i];
                int ny = y+dy[j];

                if(nx<1 || ny<1) continue;
                if(vis[nx][ny]==1 || pos[nx][ny]==0) continue;

                moves[nx][ny] = moves[x][y]+1;
                vis[nx][ny]=1;

                qu.push({nx, ny});
            }
        }
    }
}

void solve()
{
    for(int i=0; i<=1; i++) cin>>x[i]>>y[i];

    int n; cin>>n;

    for(int i=1; i<=n; i++)
    {
        int r, a, b;
        cin>>r>>a>>b;
        for(int j=a; j<=b; j++) pos[r][j]=1;
    }

    BFS(x[0], y[0]);

    int ans = moves[x[1]][y[1]];
    if(ans==0) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}