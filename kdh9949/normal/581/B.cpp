#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a[101010],ans[101010],mx;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=n;i>=1;i--){
        ans[i]=max(0,mx-a[i]+1);
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}