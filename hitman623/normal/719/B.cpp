#include <iostream>
#include<math.h>
using namespace std;
  char c[3],a[100001];
int main()
{
   long n,i,b=0,r=0,ans,h,d[2]={0};
   cin>>n;
   cin>>a;
   for(i=0;i<n;++i)
   {
      if(a[i]=='b') b++;
      else r++;
   }
   c[0]='b';
   c[1]='r';
  for(i=0;i<n;++i)
  {
    if(a[i]!=c[i%2]) { d[i%2]++;
                     }
  }
  int u=d[0]<d[1]?d[1]:d[0];
  d[0]=0;d[1]=0;
  c[0]='r';
  c[1]='b';
   for(i=0;i<n;++i)
  {
    if(a[i]!=c[i%2]) { d[i%2]++;
                     }
  }
  int v=d[0]<d[1]?d[1]:d[0];
  if (v<u)
  ans=v;
  else ans=u;
  cout<<ans;
    return 0;
}