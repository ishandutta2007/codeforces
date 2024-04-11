#include <cstdio>

int n;
double adj[20][20];

double win[1<<18][20];

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        win[1<<i][i] = 1;
        for (int j=0; j<n; j++) {
            scanf("%lf",&adj[i][j]);
        }
    }
    for (int i=1; i<(1<<n); i++) {
        int bitcnt = 0;
        for (int j=0; j<n; j++) {
            if((i>>j)&1) bitcnt++;
        }
        if(bitcnt <= 1) continue;
        int psb = bitcnt * (bitcnt - 1) / 2;
        
        for (int j=0; j<n; j++) {
            if((i>>j)%2 == 0) continue;
            for (int k=j+1; k<n; k++) {
                if((i>>k)%2 == 0) continue;
                for (int l=0; l<n; l++) {
                    win[i][l] += 1.0 * (adj[j][k] * win[i ^ (1<<k)][l] + adj[k][j] * win[i ^ (1<<j)][l]) / psb;
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        printf("%lf ",win[(1<<n)-1][i]);
    }
}