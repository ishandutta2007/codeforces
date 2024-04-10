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
    long n,x,y,i,a=0,b=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x>>y;
        if(x>y) a++;
        else if(y>x) b++;
    }
    if(a>b) cout<<"Mishka";
    else if(b>a) cout<<"Chris";
    else cout<<"Friendship is magic!^^";
    return 0;
}