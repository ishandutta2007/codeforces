#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,a,x[100001],i,s,m,b,v,t;
    cin>>n>>a;
    for(i=0;i<n;++i)
        cin>>x[i];
    sort(x,x+n);
    t=upper_bound(x,x+n,a)-x;
    if(n==1) {cout<<0;exit(0);}
    if(t==0)
    {
        cout<<x[n-2]-a;
    }
    else if(t==n)
    {
        cout<<a-x[1];
    }
    else
    {
    s=abs(x[n-1]-a)+abs(x[n-1]-x[1]);
    b=abs(a-x[1])+abs(x[n-1]-x[1]);
    m=abs(a-x[0])+abs(x[n-2]-x[0]);
    v=abs(x[n-2]-a)+abs(x[n-2]-x[0]);
    if(s<b) b=s;
    if(m<v) v=m;
    if(b<v) cout<<b;
    else cout<<v;
    }
    return 0;
}