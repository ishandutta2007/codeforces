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
    long n,h,k,a[100005],i,cur=0,tim=0,t;
    cin>>n>>h>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    {
        t=(cur-(h-a[i]))/k+!!((cur-(h-a[i]))%k);
        if(t<0 || cur<(h-a[i])) t=0;
        tim+=t;
        cur=max((long)0,cur-k*t)+a[i];
        
    }
    tim+=cur/k+!!(cur%k);
    cout<<tim;
    return 0;
}