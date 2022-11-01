#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>

using namespace std;

const int MAXN=300000;
int t[MAXN],a[MAXN],b[MAXN],ans,n;
set<int>s;

void add(int x)
{
  while(x<=n)
    {
      t[x]++;
      x+=x&(-x);
    }
}

int f(int x)
{
  int ans1=0;
  while(x)
    {
      ans1+=t[x];
      x-=x&(-x);
    }
  return ans1;
}

void run()
{
  memset(t,0,sizeof t);
  for(int i=0;i<n;i++)
    {
      b[i]+=a[i]-f(a[i]+1);
      add(a[i]+1);
    }
}

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  run();
  for(int i=0;i<n;i++)
      cin>>a[i];
  run();
  for(int i=n-1;i>=0;i--)
    {
      if(i)
	b[i-1]+=b[i]/(n-i);
      b[i]%=n-i;
    }
  memset(t,0,sizeof t);
  for(int i=0;i<n;i++)
    s.insert(i);
   for(int i=0;i<n;i++)
    {
      int l=0,r=n-1;
      while(l<r)
	{
	  int mid=(l+r)/2;
	  if(mid-f(mid+1)>=b[i])
	    r=mid;
	  else
	    l=mid+1;
	}
      ans=*(--s.upper_bound(l));
      add(ans+1);
      s.erase(ans);
      cout<<ans<<" ";
      }
  cout<<endl;
}