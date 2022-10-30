// Hydro submission #6259233b37de167dd82bd922@1650008892007
#include<bits/stdc++.h>
using namespace std;
int x[1000],b,t;
int main()
{
    int n,a,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a<=b)
        x[t]=b,t++;
        b=a;
    }
    x[t]=b,t++;
    printf("%d\n",t);
    for(i=0;i<t;i++)
    printf("%d ",x[i]);
    return 0;
}