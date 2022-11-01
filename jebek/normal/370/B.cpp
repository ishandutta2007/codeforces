#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

long long n,t[200],a[200][200],b[200];
bool m,ans[200];

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>t[i];
      for(int j=0;j<t[i];j++)
	  cin>>a[i][j];
    }
  for(int i=0;i<n;i++)
    {
      memset(b,0,sizeof b);
      for(int j=0;j<t[i];j++)
	b[a[i][j]]=1;
      for(int j=0;j<n;j++)
	{
	  if(i==j)
	    continue;
	  m=false;
	  for(int u=0;u<t[j] && m==false;u++)
	    if(b[a[j][u]]==0)
	      m=true;
	  if(m==false)
	    {
	      //    cout<<i<<" "<<j<<endl;
	      ans[i]=true;
	      break;
	    }
	}
    }
  for(int i=0;i<n;i++)
    if(ans[i])
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
}