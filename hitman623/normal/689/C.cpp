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
long n,w;
long check(long mid)
{
    w=0;
    long i,t;
    for(i=2;i*i*i<=mid;++i)
    {
        t=mid/(i*i*i);
        if(t==0) break;
        w+=t;
    }
    if(w<n) return 0;
    else return 1;
}
int main()
{
    cin>>n;
    long lo=0,hi=5e16,mid;
    while(hi-lo>1)
    {
        mid=(lo+hi)/2;
        if(check(mid))
        hi=mid;
        else lo=mid;
    }
    check(lo);
    if(w==n) {cout<<lo;exit(0);}
    check(mid);
    if(w==n) {cout<<mid;exit(0);}
    check(hi);
    if(w==n) {cout<<hi;exit(0);}
    cout<<-1;
    return 0;
}