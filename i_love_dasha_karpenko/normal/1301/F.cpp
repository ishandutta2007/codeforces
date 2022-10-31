//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1007;
const int CSZ = 40+3;
const int INF = 1e9+7;
int col[N][N];
queue<pair<int,int> > Q;
int n,m,k,CD[CSZ][CSZ],dist[CSZ][N][N],upd[CSZ];
vector<pair<int,int> > V[CSZ];
void add(int cur,int a,int b,int dx,int dy){
    int x = a+dx,y = b+dy;
 
    if ((dx && dy) || !(dx || dy) || x<1 || x>n || y<1 || y>m || dist[cur][x][y]!=-1)
        return;
 
    dist[cur][x][y] = dist[cur][a][b]+1;
    Q.push({x,y});
 
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin>>n>>m>>k;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            cin>>col[i][j];
            V[col[i][j]].push_back({i,j});
        }
    }
    for(int i = 1;i<=k;++i)
        for(int j = 1;j<=k;++j)
            if (i!=j)
                CD[i][j] = INF;
 
    for(int cur = 1;cur<=k;++cur){
        memset(dist[cur],-1,sizeof(dist[cur]));
        memset(upd,0,sizeof(upd));
        for(auto [x,y]:V[cur])
            dist[cur][x][y] = 0,Q.push({x,y});
        CD[cur][cur] = 0;
        while(!Q.empty()){
            int x = Q.front().first,y = Q.front().second;
            Q.pop();
            CD[cur][col[x][y]] = min(CD[cur][col[x][y]],dist[cur][x][y]);
            if (upd[col[x][y]]==0){
                for(auto [i,j]:V[col[x][y]]){
                    if (dist[cur][i][j]==-1){
                        dist[cur][i][j] = dist[cur][x][y]+1;
                        Q.push({i,j});
                    }
 
                }
                upd[col[x][y]] = 1;
            }
            for(int dx = -1;dx<=1;++dx)
                for(int dy = -1;dy<=1;++dy)
                    add(cur,x,y,dx,dy);
 
        }
    }
 
 
    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int d = min(abs(x1-x2)+abs(y1-y2),CD[col[x1][y1]][col[x2][y2]]+2);
 
 
        for(int i = 1;i<=k;++i){
            d = min(d,dist[i][x1][y1]+dist[i][x2][y2]+1);
            d = min(d,dist[i][x1][y1]+CD[i][col[x2][y2]]+2);
            d = min(d,dist[i][x2][y2]+CD[i][col[x1][y1]]+2);
        }
        cout<<d<<endl;
    }
    return 0;
}