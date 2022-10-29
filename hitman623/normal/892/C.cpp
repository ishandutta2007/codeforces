#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long n,a[2004],i,j,g=0,ans=1000000000,c=0;
int main()
{
    io
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]==1) c++;
        g=__gcd(a[i],g);
    }
    if(c)
    {
        cout<<n-c;
        return 0;
    }
    if(g!=1) {cout<<-1;return 0;}
    for(i=0;i<n;++i)
    {
        long g=0;
        for(j=i;j<n;++j)
        {
            g=__gcd(g,a[j]);
            if(g==1) break;
        }
        if(j!=n)
        ans=min(ans,j-i);
    }
    cout<<n-1+ans;
    return 0;
}