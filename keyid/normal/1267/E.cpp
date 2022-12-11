#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXM=105;

int v[MAXM],a[MAXM][MAXM];
bool ok[MAXM];
vector <int> tmp;

int cal(int n,int m)
{
	int ret=0,sum=0;
	tmp.clear();
	for (int i=1;i<=m;i++)
		if (v[i]>=0)
		{
			ret++;
			sum+=v[i];
		}
		else
			tmp.pb(-v[i]);
	sort(tmp.begin(),tmp.end());
	for (int x:tmp)
		if (sum-x>=0)
		{
			sum-=x;
			ret++;
		}
	return ret;
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	int ans=-1,p;
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<=m;j++)
			v[j]=a[j][i]-a[j][n];
		int ret=cal(n,m);
		if (ans<ret)
		{
			ans=ret;
			p=i;
		}
	}
	printf("%d\n",m-ans);
	for (int i=1;i<=m;i++)
		v[i]=a[i][p]-a[i][n];
	int sum=0;
	tmp.clear();
	for (int i=1;i<=m;i++)
		if (v[i]>=0)
		{
			sum+=v[i];
			ok[i]=true;
		}
		else
			tmp.pb(i);
	sort(tmp.begin(),tmp.end(),[](const auto &x,const auto &y){ return v[x]>v[y]; });
	for (int x:tmp)
		if (sum+v[x]>=0)
		{
			sum+=v[x];
			ok[x]=true;
		}
	for (int i=1;i<=m;i++)
		if (!ok[i])
			printf("%d ",i);
	return 0;
}