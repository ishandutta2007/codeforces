#include<stdio.h>
#include<algorithm>

int cnt[4];

int main()
{
    int ans;
    int i,n,a;
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&a);cnt[a-1]++;}
    ans=cnt[3];
    ans+=cnt[2];
    cnt[0]-=cnt[2];
    ans+=(cnt[1]+1)/2;
    if(cnt[1]%2)cnt[0]-=2;
    if(cnt[0]>0)ans+=(cnt[0]+3)/4;
    printf("%d",ans);
}