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
    long n,i,ans=0;
    cin>>n;
    for(i=1;i<=n;++i)
    if(n%i==0)
    {
        long d=i,c=0;
        while(d) d/=2,c++;
        if(c%2==0) continue;
        long m=(c+1)/2;
        if(i==((1<<m)-1)*(1<<(m-1))) ans=max(ans,i);
    }
    cout<<ans;
    return 0;
}