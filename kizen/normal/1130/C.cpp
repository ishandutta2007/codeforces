#include <bits/stdc++.h>

using namespace std;

int N;
int sx, sy, ex, ey;
int arr[54][54];
vector < pair < int, int > > s, e;
int wx[4] = {-1, 0, 1, 0}, wy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int val){
    arr[x][y] = 2;
    if(val==2) s.push_back(make_pair(x, y));
    else e.push_back(make_pair(x, y));
    for(int i=0;i<4;++i){
        int nx = x+wx[i], ny = y+wy[i];
        if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&arr[nx][ny]==0){
            dfs(nx, ny, val);
        }
    }
}

int main(){
    scanf("%d", &N);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) scanf("%1d", arr[i]+j);
    dfs(sx, sy, 2);
    if(arr[ex][ey]==2){
        puts("0"); return 0;
    }
    dfs(ex, ey, 3);
    int ans = (int)1e9;
    for(auto&i:s) for(auto&j:e){
        ans = min(ans, (i.first-j.first)*(i.first-j.first)+(i.second-j.second)*(i.second-j.second));
    }
    printf("%d", ans);
    return 0;
}