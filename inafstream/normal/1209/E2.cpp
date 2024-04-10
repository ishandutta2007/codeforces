#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

int t,n,m,a[15][2005],dp[15][1<<12],val[15],tmp[1<<12];
vector<int> seq;
set<int> ss;
struct node
{
	int x,y,v;
}s[24005];

bool cmp(node x,node y)
{
	return x.v>y.v;
}

int main()
{
	int i,j,k,l;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		rep(i,n)
		{
			rep(j,m)
			{
				scanf("%d",&a[i][j]);
				s[(i-1)*m+j].x=j;
				s[(i-1)*m+j].y=i;
				s[(i-1)*m+j].v=a[i][j];
			}
		}
		
		seq.clear();
		sort(s+1,s+n*m+1,cmp);
		int c=0;ss.clear();
		rep(i,n*m)
		{
			if (c>=n) break;
			if (ss.count(s[i].x)) continue;
			ss.insert(s[i].x);
			c++;
			seq.push_back(s[i].x);
		}
		sort(seq.begin(),seq.end());
		
		memset(dp,0,sizeof(dp));
		for (i=0;i<seq.size();i++)
		{
			for (j=0;j<n;j++)
			{
				rep(k,n) val[(j+k)%n]=a[k][seq[i]];
				for (k=0;k<(1<<n);k++) tmp[k]=dp[i][k]; 
				for (k=0;k<(1<<n);k++)
				{
					for (l=0;l<n;l++)
					{
						if ((k>>l)&1)
						{
							tmp[k]=max(tmp[k],tmp[k^(1<<l)]+val[l]);
						}
					}
				}
				for (k=0;k<(1<<n);k++) dp[i+1][k]=max(dp[i+1][k],tmp[k]);
			}
		}
		
		printf("%d\n",dp[seq.size()][(1<<n)-1]);
	}
	return 0;
}