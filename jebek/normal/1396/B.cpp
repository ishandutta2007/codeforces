#include<bits/stdc++.h>
using namespace std;

int n,sum,MAX;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int qw;
  cin>>qw;
  while(qw--)
    {
      cin>>n;
      sum=0;
      MAX=0;
      for(int i=0;i<n;i++)
	{
	  int a;
	  cin>>a;
	  sum+=a;
	  MAX=max(MAX,a);
	}
      if(MAX*2 > sum || sum%2==1)
	cout<<"T"<<endl;
      else
	cout<<"HL"<<endl;
    }
}