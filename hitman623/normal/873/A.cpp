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
    long n,k,x,i,a[1005],s=0;
    cin>>n>>k>>x;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=n-1;i>=0;i--)
    if(a[i]>x && k>0)
    s+=x,k--;
    else s+=a[i];
    cout<<s;
    return 0;
}