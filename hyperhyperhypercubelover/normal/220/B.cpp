#include<cstdio>
#include<algorithm>
#include<vector>

int a[100001];
int b[100001];

std::vector<int> d[100001];
int q[100001],qn;

int c[500][100001];

int main()
{
	int s,e,r;
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	std::sort(b,b+n);
    for(i=0;i<n;i++)a[i]=std::lower_bound(b,b+n,a[i])-b;
    for(i=0;i<n;i++)d[a[i]].push_back(i+1);
    for(i=0;i<n;i++)if(b[i]<=d[i].size())q[qn++]=i;
    for(i=0;i<qn;i++)
	{
		for(j=0;j<d[q[i]].size();j++)c[i][d[q[i]][j]]++;
		for(j=1;j<=n;j++)c[i][j]+=c[i][j-1];
	}
    for(i=0;i<m;i++)
	{
		scanf("%d%d",&s,&e);
		r=0;
		for(j=0;j<qn;j++)if(c[j][e]-c[j][s-1]==b[q[j]])r++;
		printf("%d\n",r);
	}
}