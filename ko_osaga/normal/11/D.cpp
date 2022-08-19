#include <cstdio>
#include <cstring>
typedef long long lint;

int n, adj[20][20];

long long dp[1<<18][19];

long long f(int bit, int pos){
    if(~dp[bit][pos]) return dp[bit][pos];
    long long ret = 0;
    for (int i=0; i<n; i++) {
        if(pos != i && adj[pos][i]){
            if(i == n-1) ret++;
            else if((bit >> i) & 1){
                ret += f(bit ^ (1<<i),i);
            }
        }
    }
    return dp[bit][pos] = ret;
}

int main(){
    int m;
    scanf("%d %d",&n,&m);
    while (m--) {
        int x,y;
        scanf("%d %d",&x,&y);
        x--;y--;
        adj[x][y] = adj[y][x] = 1;
    }
    long long ret = 0;
    while (n>1) {
        memset(dp,-1,sizeof(dp));
        for (int i=0; i<n-1; i++) {
            if(adj[n-1][i]) ret--;
        }
        ret += f((1<<(n-1))-1,n-1);
        n--;
    }
    printf("%lld",ret/2);
}