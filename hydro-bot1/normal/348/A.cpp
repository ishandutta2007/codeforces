// Hydro submission #62ef1f2574879b352565d692@1659838245612
#include<bits/stdc++.h>
using namespace std;
long long s; 
int main()
{
    int n,x,mx=0,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x,s+=x;
        mx=max(mx,x);
    }
    printf("%d\n",max(mx,int(ceil(1.0*s/(n-1)))));
    return 0;
}