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
    vll v1,v2;
    long n,i,x,a[200005],j;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        v1.pb({x,i});
    }
    for(i=0;i<n;++i)
    {
        cin>>x;
        v2.pb({x,i});
    }
    j=n-1;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(i=0;i<n;++i)
    a[v2[i].y]=v1[j--].x;
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}