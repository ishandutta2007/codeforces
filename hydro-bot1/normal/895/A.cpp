// Hydro submission #62591de837de167dd82bc7c6@1650007529015
#include<bits/stdc++.h>
using namespace std;
int a[360];
int main()
{
    int n,i,j,k,s=360,t;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    for(j=i;j<n;j++)
    {
        t=0;
        for(k=i;k<=j;k++)
        t+=a[k],s=min(s,abs(t-180));
    }
    printf("%d\n",s*2);
    return 0;
}