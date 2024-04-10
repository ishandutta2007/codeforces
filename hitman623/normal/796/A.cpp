#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long n,a[100005],i,m,k,d1=1e9,d2=1e9;
    cin>>n>>m>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=m-1;i<n;++i)
    if(a[i]!=0 && a[i]<=k)
    {
        d1=(i-m+1)*10;
        break;
    }
    for(i=m-1;i>=0;--i)
    if(a[i]!=0 && a[i]<=k)
    {
        d2=(m-1-i)*10;
        break;
    }
    cout<<min(d1,d2);
    return 0;
}