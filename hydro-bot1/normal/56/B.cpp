// Hydro submission #62e23dbac21c1686c727906d@1658994107016
#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001];
int main()
{
    int n,m,p=0,q=0,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    if(a[i]!=b[i])
    {
        p=i;
        break;
    }
    for(j=n;j>=1;j--)
    if(a[j]!=b[j])
    {
        q=j;
        break;
    }
    while(i++&&j--&&i<=j)
    if(a[i]!=b[j])
    {
        printf("0 0\n");
        return 0;
    }
    printf("%d %d\n",p,q);
    return 0;
}