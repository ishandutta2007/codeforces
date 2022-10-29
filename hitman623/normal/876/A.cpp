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
    long n,a,b,c;
    cin>>n>>a>>b>>c;
    n--;
    if(n==0) {cout<<0;exit(0);}
    if(a<=b && a<=c) cout<<n*a;
    else if(b<=a && b<=c) cout<<n*b;
    else if(a<=b) cout<<a+(n-1)*c;
    else cout<<b+(n-1)*c;
    return 0;
}