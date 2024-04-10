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
#define hell 99991
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    long n,i;
    cin>>n;
    for(i=n/2;i>=1;--i)
    if(__gcd(i,n-i)==1)
    {cout<<i<<" "<<n-i;return 0;}
    return 0;
}