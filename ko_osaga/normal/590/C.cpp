#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

char str[1005][1005];
int dist[3][1005][1005];
int n, m;

queue<int> qx, qy;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int getDist(char s, int p){
    while(!qx.empty()) qx.pop(), qy.pop();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(str[i][j] == s){
                qx.push(i);
                qy.push(j);
                dist[p][i][j] = 0;
            }
        }
    }
    while(!qx.empty()){
        int xf = qx.front();
        int yf = qy.front();
        qx.pop();
        qy.pop();
        for(int i=0; i<4; i++){
            if(xf + dx[i] < 0 || xf + dx[i] >= n || yf + dy[i] < 0 || yf + dy[i] >= m){
                continue;
            }
            if(dist[p][xf + dx[i]][yf + dy[i]] < 1e8) continue;
            if(str[xf + dx[i]][yf + dy[i]] == '#') continue;
            dist[p][xf + dx[i]][yf + dy[i]] = dist[p][xf][yf] + 1;
            qx.push(xf + dx[i]);
            qy.push(yf + dy[i]);
        }
    }
    return 1e8;
}

int vis[1005][1005];
int fuckingsex(char s, char e){
    memset(vis,0,sizeof(vis));
    while(!qx.empty()) qx.pop(), qy.pop();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(str[i][j] == s){
                qx.push(i);
                qy.push(j);
                vis[i][j] = 1;
            }
        }
    }
    while(!qx.empty()){
        int xf = qx.front();
        int yf = qy.front();
        if(str[xf][yf] == e){
            return vis[xf][yf] - 2;
        }
        qx.pop();
        qy.pop();
        for(int i=0; i<4; i++){
            if(xf + dx[i] < 0 || xf + dx[i] >= n || yf + dy[i] < 0 || yf + dy[i] >= m){
                continue;
            }
            if(vis[xf + dx[i]][yf + dy[i]]) continue;
            if(str[xf + dx[i]][yf + dy[i]] == '#') continue;
            vis[xf + dx[i]][yf + dy[i]] = vis[xf][yf] + 1;
            qx.push(xf + dx[i]);
            qy.push(yf + dy[i]);
        }
    }
    return 1e8;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%s",str[i]);
    }
    memset(dist,0x3f,sizeof(dist));
    getDist('1', 0);
    getDist('2', 1);
    getDist('3', 2);
    lint ret = 1e8;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ret = min(ret, 1ll * dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);
        }
    }    
    int t1 = fuckingsex('1', '2');
    int t2 = fuckingsex('2', '3');
    int t3 = fuckingsex('3', '1');
    ret = min(ret,1ll* t1 + t2 + t3 - max(max(t1, t2), t3));
    if(ret > 1e7) puts("-1");
    else printf("%lld",ret);
}