#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],b[1005];;
bool judge(int m)
{
    long long sum=0;
    for(int i=1;i<=m;i++)
        b[i]=a[i];
    sort(b+1,b+1+m);
    if(m%2==0)
    {
        for(int i=1;i<=m;i+=2)
            sum+=b[i+1];
    }
    else
    {
        sum=b[1];
        for(int i=2;i<=m;i+=2)
            sum+=b[i+1];
    }
    return sum<=k;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=0,r=n,ans;
    while(l<=r)
    {
        int m=l+r>>1;
        if(judge(m)) ans=m,l=m+1;
        else r=m-1;
    }
    printf("%d\n",ans);
}