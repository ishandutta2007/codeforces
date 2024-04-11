#include <cstdio>

int n, x[25], y[25];
int dp[1<<24];

int dist[25][25];
short tra[1<<24];

int main(){
    int xp,yp;
    scanf("%d %d %d",&xp,&yp,&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&x[i],&y[i]);
        x[i] -= xp;
        y[i] -= yp;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            dist[i][j] = x[i] * x[i] + y[i] * y[i] + x[j] * x[j] + y[j] * y[j] + (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
        }
    }
    for (int bit=1; bit<(1<<n); bit++) {
        dp[bit] = 1e9;
        int i;
        for (i=0; (bit>>i)%2 == 0; i++);
        int t = dp[bit^(1<<i)] + dist[i][i];
        if(dp[bit] > t){
            dp[bit] = t;
            tra[bit] = -i-1;
        }
        for (int j=i+1; j<n; j++) {
            if((bit >> j) & 1){
                int t = dp[bit^(1<<i)^(1<<j)] + dist[i][j];
                if(dp[bit] > t){
                    dp[bit] = t;
                    tra[bit] = i * n + j;
                }
            }
        }
    }
    int ret = dp[(1<<n)-1];
    printf("%d\n",ret);
    int start_bit = ((1<<n)-1);
    int x = n;
    while (x >= 1) {
        if(tra[start_bit] < 0){
            printf("0 %d ",-tra[start_bit]);
            x -= 1;
            start_bit ^= (1<<(-tra[start_bit]-1));
            continue;
        }
        int np = tra[start_bit] / n;
        int np2 = tra[start_bit] % n;
        printf("0 %d %d ",np+1,np2+1);
        start_bit ^= (1<<np);
        start_bit ^= (1<<np2);
        x -= 2;
    }
    printf("0");
}