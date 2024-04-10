#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long double n,a[200005],s=0,ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long i,k;
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<k;++i)
    s+=a[i];
    ans+=s;
    for(i=k;i<n;++i)
    {
        s+=a[i];
        s-=a[i-k];
        ans+=s;
    }
    cout<<fixed<<setprecision(12);
    cout<<ans/(n-k+1);
    return 0;
}