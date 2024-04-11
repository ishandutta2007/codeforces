#include <cstdio>

long long a[505],b[505];
int n,m;
int dp[505][505];
int trax[505][505], tray[505][505];

void track(int p, int q){
    if(p == 0) return;
    track(trax[p][q],tray[p][q]);
    if(a[p] == b[q]) printf("%lld ",a[p]);
}

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%lld",&a[i]);
    }
    scanf("%d",&m);
    for (int i=1; i<=m; i++) {
        scanf("%lld",&b[i]);
    }
    int mpx = 0, mpy = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if(a[i] != b[j]){
                dp[i][j] = dp[i][j-1];
                trax[i][j] = i;
                tray[i][j] = j-1;
            }
            if(a[i] == b[j]){
                dp[i][j] = 1;
                for (int k=1; k<i; k++) {
                    if(a[k] < a[i]){
                        if(dp[k][j] + 1 > dp[i][j]){
                            dp[i][j] = dp[k][j] + 1;
                            trax[i][j] = k;
                            tray[i][j] = j;
                        }
                    }
                }
            }
            if(dp[i][j] > dp[mpx][mpy]) mpx = i, mpy = j;
        }
    }
    printf("%d\n",dp[mpx][mpy]);
    track(mpx,mpy);
}