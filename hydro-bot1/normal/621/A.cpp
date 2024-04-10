// Hydro submission #625507d017cd4d0a417648b4@1649739730566
#include<bits/stdc++.h>
using namespace std;
int o[100000],t;
long long s;
int main()
{
    int i,n,m;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        if(m%2)
        {
            o[t]=m;
            t++;
        }
        else s+=m;
    }
    sort(o,o+t);
    for(i=0;i<t;i++)
    s+=o[i];
    if(t%2) s-=o[0];
    printf("%lld\n",s);
    return 0;
}