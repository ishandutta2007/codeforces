#include<iostream>
#include<algorithm>

using namespace std;

long long n,m,a[100][100],ans;

int main()
{
  cin>>n>>m;
  ans=4;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      {
	cin>>a[i][j];
	if(a[i][j]==1)
	  {
	    if(i==0 || i==n-1 || j==0 || j==m-1)
	      {
		ans=2;
     	      }
	  }
      }
  cout<<ans<<endl;
}