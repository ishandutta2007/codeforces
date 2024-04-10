#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

const int maxn=2000;
int n;
long long r,a[maxn];
long double h[maxn];

int main()
{
  cin>>n>>r;
  cout<<fixed<<setprecision(20);
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
      h[i]=r;
      for(int j=0;j<i;j++)
	{
	  int x=a[j];
	  if(x>a[i]) x=2*a[i]-x;
	  if(a[i]-x>2*r) continue;
	  h[i]=max(h[i],sqrt((long double)4*r*r-(a[i]-x)*(a[i]-x))+h[j]);
	}
      cout<<h[i]<<" ";
    }
  cout<<endl;
}