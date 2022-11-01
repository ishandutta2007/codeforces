#include<bits/stdc++.h>
using namespace std;

const int maxn=1e4;
long long n,k1,k2,a[maxn];
long long ans;

int main()
{
  cin>>n>>k1>>k2;
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    {
      int tmp;
      cin>>tmp;
      a[i]=abs(a[i]-tmp);
    }
  k1+=k2;
  while(k1--)
    {
      int ind=0;
      for(int i=1;i<n;i++)
	if(a[i]>a[ind])
	  ind = i;
      if(a[ind]==0)
	a[ind]++;
      else
	a[ind]--;
    }
  for(int i=0;i<n;i++)
    ans+=a[i]*a[i];
  cout<<ans<<endl;
}