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
    long n,i,a[100],s[101]={0},dp[100][2];
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    s[n-1]=a[n-1];
    for(i=n-2;i>=0;--i)
    s[i]+=s[i+1]+a[i];
    dp[n-1][0]=a[n-1];
    dp[n-1][1]=a[n-1];
    for(i=n-2;i>=0;--i)
    {
        dp[i][0]=max(a[i]+(s[i+1]-dp[i+1][1]),dp[i+1][0]);
        dp[i][1]=max(a[i]+(s[i+1]-dp[i+1][0]),dp[i+1][1]);
    }
    cout<<s[0]-dp[0][0]<<" "<<dp[0][0];
    return 0;
}