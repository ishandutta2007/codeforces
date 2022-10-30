// Hydro submission #631f2e49bdf9bc31d15c7f14@1662987849435
#include<bits/stdc++.h>
using namespace std;
int a[1001],s;
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1&&__gcd(a[i-1],a[i])!=1)
        s++;
    }
    printf("%d\n",s);
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
        if(i<n&&__gcd(a[i],a[i+1])!=1)
        printf("1 ");
    }
    return 0;
}