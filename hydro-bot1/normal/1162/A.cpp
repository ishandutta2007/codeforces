// Hydro submission #625cecf2fa9408d417fea9eb@1650257139712
#include<bits/stdc++.h>
using namespace std;
int a[50],s;
int main()
{
    int n,h,m,l,r,x,i,j;
    cin>>n>>h>>m;
    for(i=0;i<n;i++)
    a[i]=h;
    for(i=0;i<m;i++)
    {
        cin>>l>>r>>x;
        for(j=l-1;j<r;j++)
        a[j]=min(a[j],x);
    }
    for(i=0;i<n;i++)
    s+=a[i]*a[i];
    printf("%d\n",s);
    return 0;
}