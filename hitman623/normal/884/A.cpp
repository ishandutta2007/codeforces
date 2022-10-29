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
    long n,t,i,a[1001];
    cin>>n>>t;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        t-=86400-a[i];
        if(t<=0) {cout<<i+1;exit(0);}
    }
    return 0;
}