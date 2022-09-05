#include<bits/stdc++.h>
using namespace std;
 
const __int128 inf=(((__int128)1)<<125);
__int128 f[100010][12];
int n,d,la[100010][12],x,a[100010];
vector<int> ans;
 
int main()
{
	scanf("%d%d",&n,&d);
	for (int i=0; i<=n; i++)
		for (int j=0; j<12; j++) f[i][j]=inf;
	f[0][11]=1;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&x),a[i]=x;
		if (x%2==0&&d%2==1)
		{
			for (int j=0; j<12; j++) f[i][j]=f[i-1][j],la[i][j]=-j;
			continue;
		}
		if (x%5==0&&d%5!=0)
		{
			for (int j=0; j<12; j++) f[i][j]=f[i-1][j],la[i][j]=-j;
			continue;
		}
		for (int j=0; j<12; j++) 
			if (f[i][j]/x>=f[i-1][j]) f[i][j]=f[i-1][j]*x,la[i][j]=-j;
		for (int j=0; j<12; j++)
			if (f[i][j*x%10]>f[i-1][j]) f[i][j*x%10]=f[i-1][j],la[i][j*x%10]=j;
	}
	if (f[n][d]==inf) return puts("-1"),0;
	for (int i=n; i; i--)
		if (la[i][d]>=0) ans.push_back(i),d=la[i][d];
	printf("%d\n",(int)ans.size());
	for (int i=((int)ans.size())-1; i>=0; i--) printf("%d ",a[ans[i]]);puts("");
	return 0;
}