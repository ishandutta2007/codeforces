#include <cstdio>
#include <cstring>

int n,sx,sy,mod = 1e9 + 7;
char str[3][10005];
int dp[3][10005][8][2];

int f(int x, int y, int bit, int p){
    if(y == n) return p;
    if(x == 3) return f(0,y+1,bit,p);
    if(str[x][y] != '.') return f(x+1,y,bit,p);
    if(bit & (1<<x)) return f(x+1,y,bit ^ (1<<x),p);
    if(~dp[x][y][bit][p]) return dp[x][y][bit][p];
    int r = 0;
    if(x == 0 && (bit&2) == 0 && str[x+1][y] == '.')
        r = (r + f(2,y,bit,p | (sx == 2 && sy == y))) % mod;
    if(x == 1 && (bit&4) == 0 && str[x+1][y] == '.')
        r = (r + f(0,y+1,bit,p | (sx == 0 && sy == y))) % mod;
    if(y+1 < n && str[x][y+1] == '.' && !(bit & (1<<x)))
        r = (r + f(x+1,y,bit|(1<<x),p | (x == sx && (y - 1 == sy || y + 2 == sy)))) % mod;
    return dp[x][y][bit][p] = r;
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for (int i=0; i<3; i++) {
        scanf("%s",str[i]);
        for (int j=0; j<n; j++) {
            if(str[i][j] == 'O') sx = i, sy = j;
        }
    }
    printf("%d",f(0,0,0,0));
}