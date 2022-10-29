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
long n,p,q,r,a[100005],i,b[100005];
int main()
{
    io
    cin>>n>>p>>q>>r;
    for(i=0;i<n;++i)
    cin>>a[i];
    b[n-1]=r*a[n-1];
    for(i=n-2;i>=0;--i)
    b[i]=max(a[i]*r,b[i+1]);
    b[n-1]=q*a[n-1]+r*a[n-1];
    for(i=n-2;i>=0;--i)
    b[i]=max(a[i]*q+b[i],b[i+1]);
    b[n-1]=p*a[n-1]+q*a[n-1]+r*a[n-1];
    for(i=n-2;i>=0;--i)
    b[i]=max(a[i]*p+b[i],b[i+1]);
    cout<<b[0];
    return 0;
}