#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long long n,i;
long double x[100005],y[100005];
long long check(long double mid)
{
    long i,f=1;
    long double x1,y1,x2,y2,a,b,p,m,c;
    for(i=0;i<n;++i)
    {
        x1=x[(i-1+n)%n];
        y1=y[(i-1+n)%n];
        x2=x[(i+1)%n];
        y2=y[(i+1)%n];
        a=x[i];
        b=y[i];
        if(x2==x1)
        {
            if(abs(a-x1)<2*mid) {f=0;break;}
        }
        else
        {
            m=(y2-y1)/(x2-x1);
            c=y1-m*x1;
            p=abs((b-m*a-c)/sqrt(1+m*m));
            if(p<2*mid) {f=0;break;}
        }
    }
    return f;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<setprecision(11);
    cin>>n;
    for(i=0;i<n;++i)
    cin>>x[i]>>y[i];
    long double hi,lo,mid;
    hi=1e9;
    lo=0;
    mid=(lo+hi)/2;
    while(hi-lo>0.00000001)
    {
        if(check(mid))
            lo=mid;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    cout<<mid;
    return 0;
}