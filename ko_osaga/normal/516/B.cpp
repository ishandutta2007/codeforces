#include <cstdio>
#include <queue>
using namespace std;

int n,m;
char str[2005][2005];
int deg[2005][2005];

int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

queue<int> qx,qy;

bool eval_pos(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    return 1;
}

void fill(int xf, int yf, int k){
    if(k == 0){
        str[xf][yf] = '<';
        str[xf][yf+1] = '>';
    }
    if(k == 1){
        str[xf][yf] = '^';
        str[xf+1][yf] = 'v';
    }
    if(k == 2){
        str[xf][yf] = '>';
        str[xf][yf-1] = '<';
    }
    if(k == 3){
        str[xf][yf] = 'v';
        str[xf-1][yf] = '^';
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%s",str[i]);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(str[i][j] == '*') continue;
            for (int k=0; k<4; k++) {
                if(!eval_pos(i+dx[k],j+dy[k])) continue;
                if(str[i+dx[k]][j+dy[k]] == '.') deg[i][j]++;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(deg[i][j] == 1){
                qx.push(i);
                qy.push(j);
            }
        }
    }
    while (!qx.empty()) {
        int xf = qx.front();
        int yf = qy.front();
        qx.pop();
        qy.pop();
        if(deg[xf][yf] == 0) continue;
        deg[xf][yf] = 0;
        int change = -1;
        for (int k=0; k<4; k++) {
            if(!eval_pos(xf + dx[k], yf+ dy[k])) continue;
            if(str[xf+dx[k]][yf+dy[k]] == '.'){
                fill(xf,yf,k);
                change = k;
                break;
            }
        }
       // printf("killed %d %d %d %d\n",xf,yf,xf+dx[change],yf+dy[change]);
        xf += dx[change];
        yf += dy[change];
        deg[xf][yf] = 0;
        for (int k=0; k<4; k++) {
            if(!eval_pos(xf + dx[k], yf+ dy[k])) continue;
            if(str[xf+dx[k]][yf+dy[k]] == '.') deg[xf+dx[k]][yf+dy[k]]--;
            if(deg[xf+dx[k]][yf+dy[k]] == 1){
                qx.push(xf + dx[k]);
                qy.push(yf + dy[k]);
             //   printf("queue insert %d %d\n",xf+dx[k],yf+dy[k]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(str[i][j] == '.'){
                puts("Not unique");
                return 0;
            }
        }
    }
    for (int i=0; i<n; i++) {
        puts(str[i]);
    }
}