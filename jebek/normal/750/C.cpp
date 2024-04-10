#include<bits/stdc++.h>
using namespace std;

int MIN,MAX,n,a,c,d;

int main()
{
  ios_base::sync_with_stdio(false);
  MAX=1000000000;
  MIN=-MAX;
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>c>>d;
      if(d==1)
	{
	  MIN=max(MIN,1900-a);
	}
      else
	{
	  MAX=min(MAX,1899-a);
	}
      a+=c;
    }
  if(MIN>MAX)
    cout<<"Impossible\n";
  else if (MAX==1000000000)
    cout<<"Infinity\n";
  else
    cout<<MAX+a<<endl;
}