#include <cstdio>

int dx[100005][105];
int bino[100005][105];
int mod = 1e9 + 7;
int a[100005],n;

int main(){
    int m,p,q,r;
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    bino[0][0] = 1;
    for (int i=1; i<=100004; i++) {
        bino[i][0] = 1;
        for (int j=1; j<=101; j++) {
            bino[i][j] = bino[i-1][j-1] + bino[i-1][j];
            bino[i][j] %= mod;
        }
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&p,&q,&r);
        p--;
        q--;
        r++;
        dx[p][r]++;
        for (int i=r; i; i--) {
            dx[q+1][i] -= bino[q-p+r-i][r-i];
            dx[q+1][i] %= mod;
            if(dx[q+1][i] < 0) dx[q+1][i] += mod;
        }
    }
    for (int j=101; j; j--) {
        int piv = 0;
        for (int i=0; i<=n; i++) {
            piv += dx[i][j];
            piv %= mod;
            dx[i][j-1] += piv;
            dx[i][j-1] %= mod;
        }
    }
    for (int i=0; i<n; i++) {
        a[i] += dx[i][0];
        a[i] %= mod;
        if(a[i] < 0) a[i] += mod;
        printf("%d ",a[i]);
    }
}