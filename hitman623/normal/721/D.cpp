#include <bits/stdc++.h>
#define long long long
#define pll pair < long , long >
using namespace std;
int main()
{
    long n,k,x,i,a[200005],y,c=0,in=0,f;
    cin>>n>>k>>x;
    a[0]=1e10;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]<0) c++;
        if(abs(a[i])<abs(a[in])) in=i;
    }
    if(c%2==0)
    {
        f=abs(a[in])/x+1;
        f=min(f,k);
        k-=f;
        if(a[in]<0) a[in]+=f*x;
        else a[in]-=f*x;
    }
    set < pll > s;
    for(i=1;i<=n;++i)
    s.insert({abs(a[i]),i});
    while(k>0)
    {
        k--;
        i=s.begin()->second;
        if(a[i]<0)
        {
            a[i]-=x;
            s.erase(s.begin());
            s.insert({abs(a[i]),i});
        }
        else
        {
            a[i]+=x;
            s.erase(s.begin());
            s.insert({a[i],i});
        }
    }
    for(i=1;i<=n;++i)
    cout<<a[i]<<" ";
    return 0;
}