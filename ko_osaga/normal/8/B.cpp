#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int map[205][205];
bool vis[205][205];
char str[105];
int dx[255], dy[255];
char set[5] = "LRUD";

queue<int> qx, qy, d;

int main(){
    dx['L'] = -1;
    dx['R'] = 1;
    dy['U'] = -1;
    dy['D'] = 1;
    int px = 100, py = 100;
    scanf("%s",str);
    map[px][py] = 1;
    for (int i=0; str[i]; i++) {
        px += dx[str[i]];
        py += dy[str[i]];
        map[px][py] = 1;
    }
    qx.push(100);
    qy.push(100);
    d.push(0);
    vis[100][100] = 1;
    while (!qx.empty()) {
        int xf = qx.front();
        int yf = qy.front();
        int df = d.front();
        if(xf == px && yf == py){
            puts(strlen(str) > df ? "BUG" : "OK");
            return 0;
        }
        qx.pop(), qy.pop(), d.pop();
        for (int i=0; i<4; i++) {
            int nx = xf + dx[set[i]], ny = yf + dy[set[i]];
            if(vis[nx][ny] || !map[nx][ny]) continue;
            vis[nx][ny] = 1;
            qx.push(nx);
            qy.push(ny);
            d.push(df + 1);
        }
    }
}