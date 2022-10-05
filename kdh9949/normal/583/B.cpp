#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a[1010],cnt,ans,chk[1010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(chk[j])continue;
            if(a[j]<=cnt)chk[j]=1,cnt++;
            if(cnt==n)break;
        }
        if(cnt==n)break;
        ans++;
        for(int j=n;j>=1;j--){
            if(chk[j])continue;
            if(a[j]<=cnt)chk[j]=1,cnt++;
            if(cnt==n)break;
        }
        if(cnt==n)break;
        ans++;
    }
    printf("%d",ans);
}