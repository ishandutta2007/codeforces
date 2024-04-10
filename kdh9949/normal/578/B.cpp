#include <stdio.h>
#include <algorithm>

using namespace std;

int n,k,x,onlybit[64][201010];
long long a[201010],mx,ub,allor,mult=1,ans;

int main()
{
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=k;i++)mult*=x;
    for(int i=0;i<n;i++)scanf("%I64d",a+i),mx=max(mx,a[i]);
    for(ub=1;ub*2<=mx;ub*=2);
    for(int i=0;(1ll<<i)<=ub;i++){
        int cnt=-1,curbit=(1ll<<i);
        for(int j=0;j<n;j++){
            if(curbit&a[j]){
                if(cnt!=-1){cnt=-1;break;}
                cnt=j;
            }
        }
        if(cnt!=-1)onlybit[i][cnt]=1;
    }
    for(int i=0;i<n;i++)allor|=a[i];
    for(int i=0;i<n;i++){            long long callor=allor;
            for(int j=0;j<64;j++)if(onlybit[j][i])callor-=(1ll<<j);
            callor|=(mult*a[i]);
            ans=max(callor,ans);
    }
    printf("%I64d",ans);
}