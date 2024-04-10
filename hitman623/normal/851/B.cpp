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
    long x[3],y[3],i;
    for(i=0;i<3;++i)
    cin>>x[i]>>y[i];
    if((x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1])==(x[2]-x[1])*(x[2]-x[1])+(y[2]-y[1])*(y[2]-y[1]) && (y[1]-y[0])*(x[2]-x[1])!=(x[1]-x[0])*(y[2]-y[1]))
    cout<<"Yes";
    else cout<<"No";
    return 0;
}