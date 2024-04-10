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
    long n,i,a[1003],c=0;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=1;i<n-1;++i)
    if(a[i]<a[i-1] && a[i]<a[i+1])
    c++;
    else if(a[i]>a[i-1] && a[i]>a[i+1])
    c++;
    cout<<c;
    return 0;
}