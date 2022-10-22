#include <bits/stdc++.h>
using namespace std;
const int mn=52;
int a[mn],b[mn],c[mn],e[mn];
int dp[mn][mn][mn];
int main()
{
    int n,h,m,i,j,k,l,ii;
    scanf("%d%d%d",&n,&h,&m);
    for(i=0;i<m;i++)scanf("%d%d%d%d",a+i,b+i,c+i,e+i);
    for(int d=0;d<n;d++){
        for(i=1;i+d<=n;i++){
            j=i+d;
            for(k=0;k<=h;k++){
                for(l=i;l<=j;l++){
                    int pen=0;
                    for(ii=0;ii<m;ii++){
                        if(a[ii]>=i&&b[ii]<=j&&a[ii]<=l&&b[ii]>=l&&c[ii]<k)pen+=e[ii];
                    }
                    dp[i][j][k]=max(dp[i][j][k],dp[i][l-1][k]+dp[l+1][j][k]+k*k-pen);
                }
                dp[i][j][k+1]=dp[i][j][k];
            }
        }
    }
    printf("%d",dp[1][n][h]);
}