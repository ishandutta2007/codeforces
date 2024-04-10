#include <bits/stdc++.h>
#define pb push_back
#define vl vector < int >
#define pll pair < int , int >
#define vll vector < pll >
#define x first
#define y second
#define ml map < int , int >
#define mll map < pll , int >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long n,m,i,a[101][101],j,k;
long check()
{
    long i,j;
    for(i=0;i<n;++i)
    {
        vl v;
        for(j=0;j<m;++j)
        if(a[i][j]!=j+1)
        v.pb(j);
        if(v.size()>2) return 0;
    }
    return 1;
}
int main()
{
    io
    cin>>n>>m;
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
    cin>>a[i][j];
    for(i=0;i<m;++i)
    for(j=0;j<m;++j)
    {
        for(k=0;k<n;++k)
        swap(a[k][i],a[k][j]);
        if(check()) {cout<<"YES";return 0;}
        for(k=0;k<n;++k)
        swap(a[k][i],a[k][j]);
    }
    if(check())
    cout<<"YES";
    else cout<<"NO";
    return 0;
}