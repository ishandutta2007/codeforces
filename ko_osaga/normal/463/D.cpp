#include <cstdio>
#include <algorithm>
using namespace std;

int n,k;
int a[5][1005];
int idx[5][1005];
int win[1005][1005];

int dp[1005];

int f(int x){
    if(dp[x]) return dp[x];
    int res = 0;
    for (int i=1; i<=n; i++) {
        if(win[x][i]){
            res = max(res,f(i));
        }
    }
    return dp[x] = res + 1;
}

int main(){
    scanf("%d %d",&n,&k);
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
            idx[i][a[i][j]] = j;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if(i == j) continue;
            int piv = 1;
            for (int t=0; t<k; t++) {
                piv &= (idx[t][i] < idx[t][j]);
            }
            win[i][j] = piv;
        }
    }
    int res = 0;
    for (int i=1; i<=n; i++) {
        res = max(res,f(i));
    }
    printf("%d",res);
}