#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e6+100;
int n;
ll last,a[maxn],b[maxn],c[maxn],sum;
vector<int>v;

int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
      scanf("%lld",&a[i]);
      if(i>0)
	{
	  ll tmp = a[i]-last-1;
	  b[i] = last + 1;
	  last = b[i]+tmp/(i+1);
	  c[0]+=tmp/(i+1);
	  c[i+1]-=tmp/(i+1);
	  tmp=tmp%(i+1);
	  while(v.size() && tmp>0)
	    {
	      int p=v.back();
	      v.pop_back();
	      if(tmp >= i-p+1)
		{
		  tmp -= i-p+1;
		  c[p]+=1;
		  c[i+1]-=1;
		  last+=1;
		}
	      else
		{
		  c[p]+=1;
		  c[p+tmp]-=1;
		  v.push_back(p+tmp);
		  tmp=0;
		}
	    }
	  if(tmp>0)
	    {
	      c[0]+=1;
	      c[tmp]-=1;
	      v.push_back(tmp);
	      tmp=0;
	    }
	}
      else
	last = b[i]=a[i];
    }
  sum=0;
  for(int i=0;i<n;i++)
    {
      sum+=c[i];
      printf("%lld ",sum+b[i]);
    }
  printf("\n");
}