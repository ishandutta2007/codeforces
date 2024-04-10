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
    long n,m,a[55][55],i,j,ans=0,p[100000],c;
    p[0]=1;
    cin>>n>>m;
    for(i=1;i<=n*m;++i)
    p[i]=2*p[i-1];
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
    cin>>a[i][j];
    for(i=0;i<n;++i)
    {
        c=0;
        for(j=0;j<m;++j)
        c+=a[i][j];
        ans+=p[c]-1;
        ans+=p[m-c]-1;
    }
    for(i=0;i<m;++i)
    {
        c=0;
        for(j=0;j<n;++j)
        c+=a[j][i];
        ans+=p[c]-1;
        ans+=p[n-c]-1;
    }
    cout<<ans-n*m;
    return 0;
}