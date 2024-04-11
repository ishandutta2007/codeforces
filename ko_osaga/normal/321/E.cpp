#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
int a[4005][4005];

int cost(int i, int j){
    return (a[j][j] - a[i-1][j] - a[j][i-1] + a[i-1][i-1])/2;
}

int dp[805][4005];

void solve(int i, int s, int e, int ls, int le){
    int m = (s+e)/2;
    int obj = ls;
    if(s > e) return;
    if(s == e){
        for (int l=ls; l<=le; l++) {
            int r = dp[i-1][l-1] + cost(l,m);
            if(dp[i][m] > r) dp[i][m] = r, obj = l;
        }
        return;
    }
    for (int l=ls; l<=le; l++) {
        int r = dp[i-1][l-1] + cost(l,m);
        if(dp[i][m] > r) dp[i][m] = r, obj = l;
    }
    solve(i,s,m-1,ls,obj);
    solve(i,m+1,e,obj,le);
}

int main(){
    char buff[8005];
    scanf("%d %d\n",&n,&k);
    for (int i=1; i<=n; i++) {
        fgets(buff,8005,stdin);
        for(int j = 1; j <= n; j++)
        {
            a[i][j] = buff[j*2-2] - '0' + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    for (int i=1; i<=k; i++) {
        solve(i,i,n,i,n);
    }
    printf("%d",dp[k][n]);
}