#include <bits/stdc++.h>
using namespace std;

const int MAX=505;

int a,f[MAX][MAX];

int main()
{
	int n,m,b,mod;
	scanf("%d%d%d%d",&n,&m,&b,&mod);
	f[m][b]=1;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		for (int j=m-1;j>=0;j--)
			for (int k=b-a;k>=0;k--)
				f[j][k]=(f[j][k]+f[j+1][k+a])%mod;
	}
	int ans=0;
	for (int i=0;i<=b;i++) ans=(ans+f[0][i])%mod;
	printf("%d",ans);
	return 0;
}