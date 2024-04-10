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
    long c,v0,v1,a,l,cnt=1;
    cin>>c>>v0>>v1>>a>>l;
    if(c<=v0) {cout<<1;exit(0);}
    c-=v0;
    while(1)
    {
        v0+=a;
        cnt++;
        if(c<=min(v1,v0)-l)
        {cout<<cnt;exit(0);}
        c-=min(v1,v0)-l;
    }
    return 0;
}