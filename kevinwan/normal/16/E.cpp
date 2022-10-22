#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
double p[18][18],dp[1<<18];
int n;
int main()
{
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%lf",&p[i][j]);
    dp[(1<<n)-1]=1;
    for(i=(1<<n)-1;i;i--){
        int bc=__builtin_popcount(i);
        for(j=0;j<n;j++){
            if((i>>j)&1)
            for(k=j+1;k<n;k++){
                if((i>>k)&1){
                    dp[i-(1<<j)]+=dp[i]*p[k][j]/(bc*(bc-1)/2);
                    dp[i-(1<<k)]+=dp[i]*p[j][k]/(bc*(bc-1)/2);
                }
            }
        }
    }
    for(i=0;i<n;i++)printf("%lf ",dp[1<<i]);
}