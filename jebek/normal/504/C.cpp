#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=200000;
long long a[MAXN],t[MAXN],ans1,ans,k,p,f;
int n,MAX1,MIN1;
vector<int>v[MAXN];

int main()
{
  cin>>n;
  MIN1=n-1;
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
      v[a[i]].push_back(i);
      t[a[i]]++;
    }
  for(int i=0;i<n;i++)
    if(t[a[i]]%2==1)
      {
	ans1++;
	p=a[i];
	f=t[a[i]];
	t[a[i]]=0;
      }
  if(ans1>1)
    {
      cout<<0<<endl;
      return 0;
    }
  for(int i=1;i<MAXN;i++)
    if(v[i].size())
      {
	if(v[i][(int)v[i].size()/2]<n/2)
	  MIN1=min(MIN1,v[i][(int)v[i].size()/2]);
	if(v[i][((int)v[i].size()-1)/2]>(n-1)/2)
	   MAX1=max(MAX1,v[i][((int)v[i].size()-1)/2]);
      }
  if(ans1==0 || p==a[n/2])
    {
      k=n;
      while(k>MAX1+1 && (k>n/2 || a[k-1]==a[n-k]))
	k--;
      ans=n-k+1;
      //  cout<<k<<endl;
      for(int i=0;i<MIN1;i++)
	{
	  if(i>=n/2 && a[i]!=a[n-i-1])
	    break;
	  if(k==i+1)
	    k++;
	  if(n-k>i && a[i]!=a[n-i-1])
	    k=n-i;
	  ans+=n-k+1;
	  //	  cout<<i<<" "<<k<<endl;
	}
    }
  else
    {
      k=n;
      while(k>n/2+1 && k>MAX1+1 && (f>1 || a[k-1]!=p))
	{
	  if(a[k-1]==p)
	    f--;
	  k--;
	}
      ans=n-k+1;
      for(int i=0;i<min(n/2,MIN1);i++)
	{
	  if(a[i]==p)
	    f--;
	  while(n-k>i && a[i]!=a[n-i-1])
	    {
	      if(a[k]==p)
		f++;
	      k++;
	    }
	  while(k<n && f==0)
	    {
	      if(a[k]==p)
		f++;
	      k++;
	    }
	  ans+=n-k+1;
	}
    }
  cout<<ans<<endl;
}