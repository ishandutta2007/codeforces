#include<bits/stdc++.h>
typedef long long ll;
ll h,w,q,sum1[505][505],sum2[505][505];
ll a,b,c,d;
char mp[505][505];

int main()
{
    ll i,j,ret;
    scanf("%lld%lld",&h,&w);
    for(i=1;i<=h;i++) scanf("%s",mp[i]+1);
    for(i=2;i<=h;i++) {
        for(j=1;j<=w;j++) {
            if(mp[i][j]=='.' && mp[i-1][j]=='.')sum1[i][j]=1;
        }
    }
    for(i=1;i<=h;i++) {
        for(j=2;j<=w;j++) {
            if(mp[i][j]=='.' && mp[i][j-1]=='.')sum2[i][j]=1;
        }
    }
    for(i=1;i<=h;i++) {
        for(j=1;j<=w;j++) {
            sum1[i][j]=sum1[i][j]+sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1];
            sum2[i][j]=sum2[i][j]+sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1];
        }
    }
    scanf("%lld",&q);
    while(q--) {
        ret=0;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        ret+=sum1[c][d]-sum1[c][b-1]-sum1[a][d]+sum1[a][b-1];
        ret+=sum2[c][d]-sum2[c][b]-sum2[a-1][d]+sum2[a-1][b];
        printf("%lld\n",ret);
    }
}