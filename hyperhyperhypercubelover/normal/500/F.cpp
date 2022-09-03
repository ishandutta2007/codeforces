#include<cstdio>
#include<vector>
#include<algorithm>

int a[4001];
int b[4001];
int c[4001];

int s[4001],sn;
int t[4001],tn;

int d[4001][4001];
int e[4001][4001];

std::vector<int> f[20001];
std::pair<std::pair<int,int>,int> q[20000];
int r[20000];

int main()
{
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
        f[c[i]].push_back(i);
        f[c[i]+m].push_back(-i);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&q[i].first.first,&q[i].first.second);
		q[i].second=i;
	}
	std::sort(q,q+m);
	n=0;
	for(i=1;i<=20000;i++)
	{
        while(f[i].size())
		{
			if(f[i][f[i].size()-1]>0)
			{
				s[++sn]=f[i][f[i].size()-1];
				for(j=0;j<=4000;j++)d[sn][j]=d[sn-1][j];
				for(j=a[s[sn]];j<=4000;j++)d[sn][j]=std::max(d[sn][j],d[sn-1][j-a[s[sn]]]+b[s[sn]]);
			}
			else
			{
				if(!tn)
				{
                    while(sn)
					{
                        t[++tn]=s[sn--];
						for(j=0;j<=4000;j++)e[tn][j]=e[tn-1][j];
						for(j=a[t[tn]];j<=4000;j++)e[tn][j]=std::max(e[tn][j],e[tn-1][j-a[t[tn]]]+b[t[tn]]);
					}
				}
                tn--;
			}
			f[i].pop_back();
		}
		while(q[n].first.first==i)
		{
			for(j=0;j<=q[n].first.second;j++)r[q[n].second]=std::max(r[q[n].second],d[sn][j]+e[tn][q[n].first.second-j]);
			n++;
		}
	}
	for(i=0;i<n;i++)printf("%d\n",r[i]);
}