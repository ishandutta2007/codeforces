#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long n,m,k,an=1,t,i;
  cin>>n>>m>>k;
  m-=n;
  k=max(k,n-k+1);
  for(i=1;i<100000;++i)
  {
      if(i>n-k+1) t=((i-n+k)*(i-n+k-1))/2;
      else t=0;
      if(i>k) {t+=((i-k)*(i-k+1))/2;}
      if(i*i-t<=m) an=i+1;
      else {m=0;break;}
      if(i>k) {m-=i*i-t;break;}
  }
  //cout<<an<<m;
  an+=m/n;
  cout<<an;
    return 0;
}