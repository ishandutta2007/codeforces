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
    long n,i;
    cin>>n;
    cout<<3*n/2<<endl;
    for(i=2;i<=n;++i,++i)
    cout<<i<<" ";
    for(i=1;i<=n;++i,++i)
    cout<<i<<" ";
    for(i=2;i<=n;++i,++i)
    cout<<i<<" ";
    return 0;
}