#include<cstdio>
#include<algorithm>

int a[111111];
int l[111111];
int r[111111];

int main()
{
    int i,n,res=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)l[i]=std::min(l[i-1]+1,a[i]);
    for(i=n;i>=1;i--)r[i]=std::min(r[i+1]+1,a[i]);
    for(i=1;i<=n;i++)res=std::max(res,std::min(l[i],r[i]));
    printf("%d",res);
}