#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int mi=1e9,ans;
    for(int i=1;i<=100;i++)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]>i) sum+=a[j]-(i+1);
            else if(a[j]<i) sum+=(i-1)-a[j];
        }
        if(sum<mi) mi=sum,ans=i;
    }
    printf("%d %d\n",ans,mi);
}