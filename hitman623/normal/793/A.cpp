#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long long n,k,i,a[100005],ans=0;
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    for(i=n-1;i>=0;i--)
    {
        ans+=(a[i]-a[0])/k+!!((a[i]-a[0])%k);
        a[i]=a[0]-k*(!!((a[i]-a[0])%k));
    }
    for(i=1;i<n;++i)
    if(a[i]!=a[i-1]) {cout<<-1;exit(0);}
    cout<<ans;
    return 0;
}