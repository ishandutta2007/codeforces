#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int main()
{
    ll n,a[200005],i,c=0,m=3000000007;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    for(i=1;i<n;++i)
    m=min(m,a[i]-a[i-1]);
    for(i=1;i<n;++i)
    if(a[i]-a[i-1]==m) c++;
    cout<<m<<" "<<c;
    return 0;
}