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
    long n,k,t;
    cin>>n>>k;
    t=(n/2)/(k+1);
    cout<<t<<" "<<k*t<<" "<<n-(k+1)*t;
    return 0;
}