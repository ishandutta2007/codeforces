// Hydro submission #62ef1ff474879b352565d7b0@1659838453702
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,s=0,t=0,i;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>x,s+=x;n++;
    for(i=1;i<=5;i++)
    if((s+i)%n!=1) t++;
    printf("%d\n",t);
    return 0;
}