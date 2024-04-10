#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,a[1003],b[1003],i,d,q,mp[1002]={0},j,c;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]==2) d=a[i];
    }
    for(i=0;i<n;++i)
    cin>>b[i];
    for(i=1;i<=n;++i)
    if(mp[i]==0) q=i;
    for(i=0;i<n;++i)
    if(a[i]==d)
    {
        a[i]=q;
        c=0;
        for(j=0;j<n;++j)
        if(b[j]!=a[j]) c++;
        if(c==1) break;
        a[i]=d;
    }
    for(i=0;i<n;++i)
    cout<<a[i]<<" ";
    return 0;
}