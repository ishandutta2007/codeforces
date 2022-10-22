#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int mn=1e5+10;
ll ch[70][70];
int main()
{
    ll m,k,ans=0;
    int i,j;
    scanf("%lld%lld",&m,&k);
    if(m==0){
        printf("1");
        return 0;
    }
    ch[0][0]=1;
    for(i=1;i<=64;i++){
        ch[i][0]=1;
        for(j=1;j<=i;j++)ch[i][j]=ch[i-1][j]+ch[i-1][j-1];
    }
    for(k--;k>=0;k--){
        if(m==0)break;
        if(k==0){
            ans++;
            break;
        }
        if(k==1){
            if(m==1)ans+=2;
            else if(m==2)ans+=4;
            else ans+=(1LL<<m-1)+1;
            break;
        }
        for(i=0;i<64&&ch[i][k]<=m;i++);
        ans+=1LL<<(i-1);
        m-=ch[i-1][k];
    }
    printf("%lld",ans);
}