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
    long n,a[55][55],i,j,k,l,f;
    cin>>n;
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    cin>>a[i][j];
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    if(a[i][j]!=1)
    {
        f=0;
        for(k=0;k<n;++k)
        for(l=0;l<n;++l)
        if(a[i][j]==a[i][k]+a[l][j]) f=1;
        if(f==0) {cout<<"No";exit(0);}
    }
    cout<<"Yes";
    return 0;
}