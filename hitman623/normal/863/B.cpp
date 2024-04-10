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
long sol(vl v)
{
    long i,ans=0;
    for(i=0;i<v.size();++i,++i)
    ans+=v[i+1]-v[i];
    return ans;
}
int main()
{
    io
    long n,i,a[101],j,k,ans=1e9;
    cin>>n;
    for(i=0;i<2*n;++i)
    cin>>a[i];
    sort(a,a+2*n);
    for(i=0;i<2*n;++i)
    for(j=i+1;j<2*n;++j)
    {
        vl v;
        for(k=0;k<2*n;++k)
        if(k!=i && k!=j)
        v.pb(a[k]);
        ans=min(ans ,sol(v));
    }
    cout<<ans;
    return 0;
}