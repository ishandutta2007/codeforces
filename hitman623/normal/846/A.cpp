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
    long n,i,a[104],dp[104],c;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    dp[n-1]=1;
    c=(a[n-1]==0);
    for(i=n-2;i>=0;i--)
    {
        if(a[i]==1)
        dp[i]=max(n-i-c,dp[i+1]);
        else dp[i]=dp[i+1]+1,c++;
    }
    cout<<dp[0];
    return 0;
}