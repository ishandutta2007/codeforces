#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long double p,a[100005],b[100005],t=0,hi,lo,mid;
long long n,i;
long long check(long double mid)
{
    long i;
    long double t=0;
    for(i=0;i<n;++i)
    if(mid*a[i]-b[i]>0.00)
    t+=mid*a[i]-b[i];
    if(t>mid*p) return 0;
    else return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(11);
    cin>>n>>p;
    for(i=0;i<n;++i)
    {
        cin>>a[i]>>b[i];
        t=min(t,b[i]/a[i]);
    }
    hi=1e15;
    lo=0;
    for(i=0;i<80;++i)
    {
        mid=lo+(hi-lo)/2;
        if(check(mid))
            lo=mid;
        else hi=mid;
    }
    if(mid>=1e14) cout<<-1;
    else cout<<mid;
    return 0;
}