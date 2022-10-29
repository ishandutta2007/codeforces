#include <bits/stdc++.h>
using namespace std;
long n,k,i,a[200005],b[200005],d[200005],s=0;
int main()
{
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    { cin>>b[i];
      s+=b[i]; }
    for(i=0;i<n;++i)
    d[i]=a[i]-b[i];
    sort(d,d+n);
    i=0;
    while(i<n && (i<k || d[i]<0))
    s+=d[i++];
    cout<<s;
    return 0;
}