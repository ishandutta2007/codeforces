// Hydro submission #6247f337993deab656107390@1648882488099
#include<bits/stdc++.h>
using namespace std;
int c[1001],mn[1001],mx;
int main()
{
    int n,m,k,i,x;
    cin>>n>>m>>k;
    memset(mn,1000001,sizeof(mn));
    for(i=0;i<n;i++)
    {
        cin>>x;
        cin>>c[x];
        if(c[x]<mn[x])
        mn[x]=c[x];
    }
    for(i=1;i<=m;i++)
    mx+=mn[i];
    printf("%d\n",min(k,mx));
    return 0;
}