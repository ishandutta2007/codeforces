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
    long a,b,d,p=1,i;
    cin>>a>>b;
    d=min(a,b);
    for(i=1;i<=d;++i)
    p=p*i;
    cout<<p;
    return 0;
}