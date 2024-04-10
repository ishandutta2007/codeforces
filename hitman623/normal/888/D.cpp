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

int main()
{
    io
    long n,k,i,d[5]={1,0,1,2,9},cur=1,ans=0;
    cin>>n>>k;
    for(i=k;i>=0;--i)
    {
        long f=n-k+i,g=n-f;
        ans=ans+cur*d[g];
        cur=cur*(n+i-k);
        cur/=(k-i+1);
    }
    cout<<ans;
    return 0;
}