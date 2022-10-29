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
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,i,a[1003],h,c=0;
    cin>>n>>h;
    for(i=0;i<n;++i)
    {cin>>a[i];
    if(a[i]>h) c++;}
    cout<<n+c;
    return 0;
}