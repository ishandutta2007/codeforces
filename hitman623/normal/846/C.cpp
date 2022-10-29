#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    long n,ans=0,a[5005]={0},m[5005],i,j,k,in[5005],x=1,y=1,z=1;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    m[n+1]=-1e18;
    for(i=n;i>0;--i)
    {
        if(a[i]>m[i+1])
        m[i]=a[i],in[i]=i;
        else m[i]=m[i+1],in[i]=in[i+1];
    }
    for(i=1;i<=n+1;++i)
    for(j=i;j<=n+1;++j)
    {
        if(ans<a[i-1]-a[j-1]+m[j-1])
        {
            ans=a[i-1]-a[j-1]+m[j-1];
            x=i,y=j,z=in[j-1]+1;
        }
    }
    cout<<x-1<<" "<<y-1<<" "<<z-1;
    return 0;
}