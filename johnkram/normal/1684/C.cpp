#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
bool ans;
int n,m,i,j,b[MAXN],u[MAXN],v[MAXN],w[MAXN],U,V;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		vector<vector<int>> a(n,vector<int>(m));
		ans=1;
		for(i=0;i<n;i++)
		{
			u[i]=v[i]=-1;
			for(j=0;j<m;j++)scanf("%d",&a[i][j]);
			copy(a[i].begin(),a[i].end(),b);
			sort(b,b+m);
			for(j=w[i]=0;j<m;j++)if(a[i][j]!=b[j])
			{
				if(!w[i])u[i]=j;
				else if(w[i]==1)v[i]=j;
				else ans=0;
				w[i]++;
			}
		}
		if(!ans)
		{
			puts("-1");
			continue;
		}
		for(i=0;i<n;i++)if(w[i]==2)break;
		if(i==n)
		{
			puts("1 1");
			continue;
		}
		U=u[i];
		V=v[i];
		for(i=0;i<n;i++)if(w[i]==2&&(U!=u[i]||V!=v[i])||!w[i]&&a[i][U]!=a[i][V])break;
		if(i==n)printf("%d %d\n",U+1,V+1);
		else puts("-1");
	}
	return 0;
}