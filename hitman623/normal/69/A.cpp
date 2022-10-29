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
    long n,i,x,y,z,sx=0,sy=0,sz=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x>>y>>z;
        sx+=x;
        sy+=y;
        sz+=z;
    }
    if(!sx && !sy && !sz) cout<<"YES";
    else cout<<"NO";
    return 0;
}