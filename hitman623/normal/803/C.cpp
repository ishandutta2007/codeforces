#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long long n,k,i,a[1000006],m,c;
vector < long long > factors;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    m=n;
    if(k>200000 || (k*(k+1))/2>n) {cout<<-1;exit(0);}
    if(n==1) {cout<<1;exit(0);}
    for(i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            factors.pb(i);
            if(i*i!=n)
            factors.pb(n/i);
        }
    }
    sort(factors.begin(),factors.end());
    long long s=factors.size(),t;
    for(i=s-1;i>=0;i--)
    {
        t=m/factors[i];
        if((k*(k+1))/2<=t)
        break;
    }
    long long q=factors[i];
    vector < long long > ans;
    m=m/q;
    for(i=1;i<=k;++i)
    {
        ans.pb(q*i);
        m-=i;
    }
    ans[k-1]+=q*m;
    for(i=0;i<k;++i)
    cout<<ans[i]<<" ";
    return 0;
}