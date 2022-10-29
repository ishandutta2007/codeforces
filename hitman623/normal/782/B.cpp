#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
struct s
{
    long double x,v;
};
bool cmp(s a, s b)
{
    return a.x<b.x;
}
long double t=0;
long n,i;
s a[100005];
long check(long double mid)
{
  long i,f;
  t=0;
  for(i=0;i<n;++i)
  {
      if(abs(mid-a[i].x)/a[i].v-t>-0.000000001)
      {
          f=((mid-a[i].x)<0.000000001);
          t=abs(mid-a[i].x)/a[i].v;
      }
  }
  return f;
}
int main()
{
    long i;
    cout<<setprecision(10);
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i].x;
    for(i=0;i<n;++i)
    cin>>a[i].v;
    sort(a,a+n,cmp);
    long double hi=a[n-1].x+1,lo=a[0].x-1,mid=(lo+hi)/2;
    while(hi-lo>=0.0000001)
    {
        if(check(mid)) lo=mid;
        else hi=mid;
        mid=(lo+hi)/2.0;
    }
    check(mid);
    cout<<t;
    return 0;
}