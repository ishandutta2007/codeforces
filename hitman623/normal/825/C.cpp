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
    vl v;
    long n,k,d,c,a[1003],i,dp[1003],ans=1e16,l;
    cin>>n>>k;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        v.pb(a[i]);
    }
    sort(v.begin(),v.end());
    sort(a,a+n);
    dp[n-1]=0;
    for(i=n-2;i>=0;i--)
    {
        d=a[i];
        c=0;
        while((d*2)<a[i+1])
        d=d*2,c++;
        dp[i]=c+dp[i+1];
    }
    c=0;
    while(k<1e16)
    {
        l=upper_bound(v.begin(),v.end(),2*k)-v.begin();
        c++;
        k*=2;
        if(l==0) continue;
        ans=min(ans,c+dp[l-1]-1);
    }
    cout<<ans;
    return 0;
}