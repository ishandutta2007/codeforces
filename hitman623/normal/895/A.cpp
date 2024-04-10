#include <bits/stdc++.h>
#define pb push_back
#define vl vector < int >
#define pll pair < int , int >
#define vll vector < pll >
#define x first
#define y second
#define ml map < int , int >
#define mll map < pll , int >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long n,a[1001],i,t1=360,t2=0,ans=1e9,j,s;
int main()
{
    io
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    for(s=0,j=i;j<n;++j)
    s+=a[j],ans=min(ans,abs(360-2*s));
    cout<<ans;
    return 0;
}