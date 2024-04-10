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
    long n,x,a[1000],i,c=0,ans=0;
    cin>>n>>x;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;++i)
    if(a[i]<x) c++;
    else if(a[i]==x) ans++;
    ans+=x-c;
    cout<<ans;
    return 0;
}