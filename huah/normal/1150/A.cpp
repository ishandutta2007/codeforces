#include<bits/stdc++.h>
using namespace std;
int a[35],b[35];
int main()
{
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int j=1;j<=m;j++)
        scanf("%d",&b[j]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    reverse(b+1,b+1+m);
    int t=b[1];
    int ans=r;
    if(a[1]<t)
        ans=max(ans,r/a[1]*t+r%a[1]);
    if(n>=2)
    for(int i=0;a[1]*i<=r;i++)
            ans=max(ans,(r-a[1]*i)/a[2]*t+(r-a[1]*i)%a[2]+i*t);
    printf("%d\n",ans);
}