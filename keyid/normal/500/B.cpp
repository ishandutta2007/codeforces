#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=310;

bool map[MAXN][MAXN];
int p[MAXN],q[MAXN];
bool vis[MAXN];


int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		q[p[i]]=i;
	}
	for (int i=0;i<n;i++)
	{
		char s[MAXN];
		scanf("%s",s);
		for (int j=0;j<n;j++) map[i][j]= s[j]=='1'?true:false;
	}
	for (int k=0;k<n;k++)
	  for (int i=0;i<n;i++)
	    for (int j=0;j<n;j++)
	      map[i][j]= map[i][j]||(map[i][k]&&map[k][j]);
	for (int i=1;i<=n;i++)
	{
		int id=q[i];
		for (int j=0;j<id;j++)
		{
		  if ((i<p[j])&&map[id][j])
		  {
		  	int d=p[j];
		  	q[d]=id;
		  	swap(p[id],p[j]);
		  	break;
		  }
		}
	}
	for (int i=0;i<n;i++) printf("%d ",p[i]);
	return 0;
}