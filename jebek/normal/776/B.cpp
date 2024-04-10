#include<bits/stdc++.h>
using namespace std;

int n;
bool mark[200000];

int main()
{
  cin>>n;
  n++;
  if(n>3) cout<<2<<endl;
  else cout<<1<<endl;
  for(int i=2;i<=n;i++)
    {
      if(!mark[i])
	{
	  cout<<1<<" ";
	  for(int j=i;j<=n;j+=i)
	    mark[j]=true;
	}
      else
	cout<<2<<" ";
    }
  cout<<endl;
}