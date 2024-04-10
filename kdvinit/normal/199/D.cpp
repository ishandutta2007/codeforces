/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int a[3][N];
int moves[3][N];
int vis[3][N];
int n, k;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 100, 100};      //100 = Temporary

bool BFS(int si, int sj)
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
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<1 || nx>2 || ny<1) continue;

            if(ny>n) return true;

            if(vis[nx][ny]==1 || a[nx][ny]==1) continue;

            moves[nx][ny] = moves[x][y]+1;
            vis[nx][ny]=1;

            if(ny<=moves[nx][ny]) continue;

            qu.push({nx, ny});
        }
    }
    return false;
}

void solve()
{
    cin>>n>>k;
    dy[2]=k;
    dy[3]=k;


    int si=1, sj=1;
    for(int i=1; i<=2; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char x; cin>>x;
            if(x=='X') a[i][j]=1;
            else a[i][j]=0;
        }
    }

    if(BFS(si, sj)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}