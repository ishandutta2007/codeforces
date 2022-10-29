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
    long m,b,x,y,ans=0;
    cin>>m>>b;
    for(x=0;x<=m*b;++x)
    {
        y=-(x/m)+b-!!(x%m);
        ans=max(ans,(y+1)*(x*(x+1))/2+(x+1)*(y*(y+1))/2);
    }
    cout<<ans;
    return 0;
}