#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+100;
int qw,n,a[maxn], t[maxn][2];

int main()
{
  cin>>qw;
  while(qw--)
    {
      cin>>n;
      for(int i=0;i<n;i++)
	{
	  cin>>a[i];
	  t[a[i]][i%2]++;
	}
      sort(a,a+n);
      string ans="YES";
      for(int i=0;i<n;i++)
	{
	  t[a[i]][i%2]--;
	  if(t[a[i]][i%2]<0)
	    ans="NO";
	}
      for(int i=1;i<=1e5;i++)
	t[i][0]=t[i][1]=0;
      cout<<ans<<endl;
    }
}