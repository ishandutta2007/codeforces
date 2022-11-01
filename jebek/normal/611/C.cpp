#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN=600;
int n,m,q;
char ch[MAXN][MAXN];
int dp1[MAXN][MAXN],dp2[MAXN][MAXN];

int main()
{
  ios_base::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      {
	cin>>ch[i][j];
	dp1[i][j]=dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
	dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1];
	if(ch[i][j]=='.' && i>1 && ch[i-1][j]=='.')
	  dp1[i][j]++;
	if(ch[i][j]=='.' && j>1 && ch[i][j-1]=='.')
	  dp2[i][j]++;
      }
  cin>>q;
  for(int i=0;i<q;i++)
    {
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      cout<<dp1[c][d]-dp1[c][b-1]-dp1[a][d]+dp1[a][b-1]+dp2[c][d]-dp2[c][b]-dp2[a-1][d]+dp2[a-1][b]<<endl;
    }
}