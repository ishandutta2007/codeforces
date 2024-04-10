#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<set>

using namespace std;

typedef long long ll;
typedef pair<long long,long long> pii;
const long long MAXN=100000+100;

long long n,m,a[MAXN],b[MAXN],t[MAXN],f;
long long dp[MAXN],x[MAXN];

long long upp(long long k)
{
    long long l=0;
    long long r=m-1;
    while(l<r)
    {
      //  cout<<l<<"*"<<r<<endl;
        long long mid=(l+r)/2;
        if(dp[mid]<k)
            l=mid+1;
        else
            r=mid;
    }
    return r;
}

long long d(ll k)
{
  //  cout<<k<<endl;
    f=upp(k);
  //  cout<<i<<endl;
    if(t[f]==1)
        return a[f];
    if((k-dp[f-1])%a[f]==0)
        return d(a[f]);
    return d((k-dp[f-1])%a[f]);
}

int main()
{
    cin>>m;
    for(long long i=0;i<m;i++)
    {
        cin>>t[i]>>a[i];
        if(t[i]==2)
            cin>>b[i];
    }
    dp[0]=1;
    for(long long i=1;i<m;i++)
    {
        if(t[i]==1)
            dp[i]=dp[i-1]+1;
        if(t[i]==2)
            dp[i]=dp[i-1]+a[i]*b[i];
   //     cout<<dp[i]<<" ";
    }
    cin>>n;
    for(long long i=0;i<n;i++)
        cin>>x[i];
    for(long long i=0;i<n;i++)
        cout<<d(x[i])<<" ";
    cout<<endl;
}