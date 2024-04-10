#include<bits/stdc++.h>
using namespace std;

long long x,d;
long long a[200000],f[60];

int main()
{
  f[0]=1;
  for(int i=1;i<60;i++)
    f[i]=f[i-1]*2;
  cin>>x>>d;
  a[0]=1;
  x--;
  int p=0,n=1;
  while(x>0)
    {
      a[n]=a[n-1];
      while(a[p]+d<=a[n]) p++;
      while(f[n-p]>x) {
	a[n]=a[p]+d;
	while(a[p]+d<=a[n]) p++;
      }
      x-=f[n-p];
      n++;
    }
  cout<<n<<endl;
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}