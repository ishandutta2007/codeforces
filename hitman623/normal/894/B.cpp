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
#define h 1000000007
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

long po(long a,long b)
{
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    long ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%h;
        a=(a*a)%h;
        b>>=1;
    }
    return ans;
}
int main()
{
    io
    long n,m,k;
    cin>>n>>m>>k;
    n--;
    m--;
    n%=h-1;
    m%=h-1;
    if(k==1)
    {
        cout<<po(2,(n*m)%(h-1));
    }
    else
    {
        if((n+m)%2)
        cout<<0;
        else cout<<po(2,(n*m)%(h-1));
    }
    return 0;
}