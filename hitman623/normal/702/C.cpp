#include <bits/stdc++.h>

using namespace std;

int main()
{
     long long  n,m,a[100000],b[100000],i,u,l,mm=0;
     cin>>n>>m;
    for(i=0;i<n;++i)
            cin>>a[i];
    for(i=0;i<m;++i)
            cin>>b[i];
    for(i=0;i<n;++i)
    {
        u=upper_bound(b,b+m,a[i])-b;
        l=lower_bound(b,b+m,a[i])-b;
        if(u==0) mm=max(mm,b[0]-a[i]);
        else if(u==m)
        {
            if(l==m) mm=max(mm,a[i]-b[m-1]);
        }
        else if(l>0)
        {
            if(u==l) mm=max(mm,min(b[u]-a[i],a[i]-b[u-1]));
        }
    }
    cout<<mm;
    return 0;
}