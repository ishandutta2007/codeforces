#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;

int x[3], y[3], dis[3][1005][1005];

pii prv[3][1005][1005];

bool valid (int X, int Y) {
    return (0 <= X && X <= 1000 && 0 <= Y && Y <= 1000);
}

int main()
{
    scanf("%d%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
    for(int k=0;k<3;k++) {
        static queue<pii> Q;
        Q.push({x[k], y[k]});
        dis[k][x[k]][y[k]] = 1;
        prv[k][x[k]][y[k]] = {-1, -1};
        while(!Q.empty()) {
            int X, Y;
            tie(X, Y) = Q.front();
            Q.pop();
            for(int i=0;i<4;i++) {
                int nx = X + "1012"[i]-'1', ny = Y + "0121"[i]-'1';
                if(!valid(nx, ny) || dis[k][nx][ny]) continue;
                dis[k][nx][ny] = dis[k][X][Y] + 1;
                prv[k][nx][ny] = {X, Y};
                Q.push({nx, ny});
            }
        }
    }
    int ax = 0, ay = 0;
    for(int i=0;i<=1000;i++) {
        for(int j=0;j<=1000;j++) {
            if(dis[0][i][j] + dis[1][i][j] + dis[2][i][j] < dis[0][ax][ay] + dis[1][ax][ay] + dis[2][ax][ay]) {
                ax = i;
                ay = j;
            }
        }
    }
    vector<pii> ans;
    for(int k=0;k<3;k++) {
        int X = ax, Y = ay;
        while(prv[k][X][Y].X != -1) {
            tie(X, Y) = prv[k][X][Y];
            ans.push_back({X, Y});
        }
    }
    ans.push_back({ax, ay});
    printf("%d\n", (int)ans.size());
    for(auto &T : ans) {
        printf("%d %d\n", T.X, T.Y);
    }
}