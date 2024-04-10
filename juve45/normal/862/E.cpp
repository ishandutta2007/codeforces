#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
using namespace std;

long long n,m,q,a[100101],b[100100],i,j,l,r,v;
long long sa, sb[100100],minb,maxb;

long long cauta()
{
  //dbg(sa);
  long long* p = lower_bound(sb+1, sb+m-n+2, sa);
  long long poz = p - sb;
  if (poz==1)
    return sb[1]-sa;
  else if (poz==m-n+2)
    return sa-sb[poz-1];
  else return min(abs(sb[poz]-sa), abs(sa-sb[poz-1]));
}

int main()
{
    cin>>n>>m>>q;
    for (i=1;i<=n;i++)
      cin>>a[i];
    for (i=1;i<=m;i++)
      cin>>b[i];
    long long sgn = 1;
    for (i=1;i<=n;i++)
    {
      sa += a[i] * sgn;
      sgn = -sgn;
    }
    sgn=1;
    for (i=1;i<=n;i++)
    {
      sb[1]+=sgn*b[i];
      sgn=-sgn;
    }
    sgn=-sgn;
    for (i=2;i<=m-n+1;i++)
    {
      sb[i]=-sb[i-1]+b[i-1]+sgn*b[i+n-1];
    }
    sort(sb+1,sb+m-n+2);
   // for(long long i = 1; i <= m-n+1; i++)
    //  cout << sb[i] << ' ';
    //cout << "sdagdsfg \n\n";
    cout<<cauta()<<'\n';
    for (i=1;i<=q;i++)
    {
      cin>>l>>r>>v;
      if ((r-l+1)%2==1)
        {
          if (l%2==1)
          sa+=v;
          else sa-=v;
        }
      cout<<cauta()<<'\n';
    }
}