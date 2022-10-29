#include <iostream>
#define h 1000000007
#define ll long long
using namespace std;

ll po(ll a,ll b)
{
  if(b==0) return 1;
  if(b==1) return a%h;
  ll m=po(a,b/2);
  if(b&1)  return (((m*m)%h)*a)%h;
  return (m*m)%h;
}
int main()
{
    ll k,a[100005],i,num,denom=2,p=1,f=1;
    cin>>k;
    for(i=0;i<k;i++)
    {   cin>>a[i];
        p*=a[i]%h;
        if(a[i]%2==0) f=0; }
    for(i=0;i<k;++i)
    denom=po(denom,a[i]);
    denom=(denom*po(2,h-2))%h;
    if(f) num=(((denom-1+h)%h)*po(3,h-2))%h;
    else  num=(((denom+1+h)%h)*po(3,h-2))%h;
    cout<<num<<"/"<<denom;
    return 0;
}