// Hydro submission #6253d0bbca53060146716ed4@1649660092059
#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    int n,m,i,x,y; 
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        a[x-1]+=y-1;
        a[x+1]+=a[x]-y;
        a[x]=0;
    }
    for(i=1;i<=n;i++)
    printf("%d\n",a[i]);
    return 0;
}