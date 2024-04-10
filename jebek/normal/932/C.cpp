#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,a,b;

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>a>>b;
  for(int i=0;i*a<=n;i++)
    if((n-i*a)%b==0)
      {
	for(int j=0;j<i;j++)
	  {
	    for(int k=2;k<=a;k++)
	      cout<<j*a+k<<" ";
	    cout<<j*a+1<<" ";
	  }
	for(int j=0;j<(n-i*a)/b;j++)
	  {
	    for(int k=2;k<=b;k++)
	      cout<<i*a+j*b+k<<" ";
	    cout<<i*a+j*b+1<<" ";
	  }
	cout<<endl;
	exit(0);
      }
  cout<<-1<<endl;
}