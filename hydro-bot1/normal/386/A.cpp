// Hydro submission #6253d3f548f78301327929a1@1649660918221
#include<bits/stdc++.h>
using namespace std;
int p[1000];
int main()
{
    int n,i,mx=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p[i];
        if(p[i]>mx)
        mx=p[i];
    }
    for(i=0;i<n;i++)
    if(p[i]==mx)
    {
        printf("%d ",i+1);
        break;
    }
    sort(p,p+n);
    printf("%d\n",p[n-2]);
    return 0;
}