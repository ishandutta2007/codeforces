#include<cstdio>
long long n,m,b,mod,bug[505],dt[505][505],sum;

int main()
{
    int i,j,k;
    scanf("%lld%lld%lld%lld",&n,&m,&b,&mod);
    for(i=0;i<n;i++)scanf("%lld",&bug[i]);
    dt[0][0]=1;
    for(i=0;i<n;i++) {
        for(j=1;j<=m;j++) {
            for(k=0;k<=b-bug[i];k++){
                dt[j][k+bug[i]]+=dt[j-1][k];
                dt[j][k+bug[i]]%=mod;
            }
        }
    }
    for(i=0;i<=b;i++){
        sum+=dt[m][i];
        sum%=mod;
    }
    printf("%lld",sum);
}