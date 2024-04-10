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
    long n,d;
    cin>>n;
    d=sqrt(n);
    if(d*d!=n)
    {
        if(n-d*d>d)
        cout<<4*(d+1);
        else cout<<4*d+2;
    }
    else cout<<4*d;
    return 0;
}