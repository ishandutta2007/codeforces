#include<bits/stdc++.h>
using namespace std;

const int MAX=320;
int n,ans;
bool mark[MAX][MAX],f[MAX][MAX][9],f1[MAX][MAX][9];
int dy[8]={1,1,0,-1,-1,-1,0,1};
int dx[8]={0,1,1,1,0,-1,-1,-1};

int main()
{
  cin>>n;
  f[160][160][0]=true;
  for(int q=0;q<n;q++)
    {
      int t;
      cin>>t;
      memset(f1,false,sizeof f1);
      for(int i=0;i<MAX;i++)
	for(int j=0;j<MAX;j++)
	  for(int k=0;k<8;k++)
	    if(f[i][j][k])
	      {
		for(int x=1;x<=t;x++)
		  mark[i+dx[k]*x][j+dy[k]*x]=true;
		int a=i+dx[k]*t,b=j+dy[k]*t;
		f1[a][b][(k+7)%8]=true;
		f1[a][b][(k+1)%8]=true;
	      }
      for(int i=0;i<MAX;i++)
	for(int j=0;j<MAX;j++)
	  for(int k=0;k<8;k++)
	    f[i][j][k]=f1[i][j][k];
    }
  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++)
      ans+=mark[i][j];
  cout<<ans<<endl;
}