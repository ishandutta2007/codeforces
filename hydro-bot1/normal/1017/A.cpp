// Hydro submission #625cea6881ef68d42bcba968@1650256489487
#include<bits/stdc++.h>
using namespace std;
int s[1000];
int main()
{
    int n,a,b,c,d,t,r=1,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d;
        s[i]=a+b+c+d;
    }
    t=s[0];sort(s,s+n);
    for(i=n-1;i;i--)
    if(s[i]>t) r++;
    printf("%d\n",r);
    return 0;
}