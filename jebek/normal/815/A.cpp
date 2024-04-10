#include<bits/stdc++.h>
using namespace std;

typedef pair<string,int> psi;
vector<psi> vec;
int n,m,a[200][200];

void row(int x)
{
  vec.push_back(psi("row ",x));
  for(int i=0;i<m;i++)
    {
      if(a[x][i]==0)
	{
	  cout<<-1<<endl;
	  exit(0);
	}
      a[x][i]--;
    }
}

void col(int x)
{
  vec.push_back(psi("col ",x));
  for(int i=0;i<n;i++)
    {
      if(a[i][x]==0)
	{
	  cout<<-1<<endl;
	  exit(0);
	}
      a[i][x]--;
    }
}
      
int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>a[i][j];
  if(n<=m)
    {
      for(int i=1;i<m;i++)
	{
	  while(a[0][i]>a[0][i-1]) col(i);
	  while(a[0][i]<a[0][i-1]) for(int j=0;j<i;j++) col(j);
	}
      for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	  while(a[i][j])
	    row(i);
    }
  else
    {
      for(int i=1;i<n;i++)
	{
	  while(a[i][0]>a[i-1][0]) row(i);
	  while(a[i][0]<a[i-1][0]) for(int j=0;j<i;j++) row(j);
	}
      for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	  while(a[i][j])
	    col(j);
    }
  cout<<vec.size()<<endl;
  for(int i=0;i<vec.size();i++)
    cout<<vec[i].first<<vec[i].second+1<<'\n';
}