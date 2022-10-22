#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define N 10005
ld f[N][1005],F[1005];
int main()
{
	int k,q,i,j;
	cin>>k>>q;
	f[1][1]=1.0;
	for(i=0;i<=k;i++)F[i]=(ld)i/(ld)k;
	for(i=2;i<=10000;i++)for(j=1;j<=k;j++)f[i][j]=f[i-1][j-1]*F[k-(j-1)]+f[i-1][j]*F[j];
	while(q--)
	{
		int xx;
		scanf("%d",&xx);
		ld tt=xx-1e-8;
		tt/=2000.0;
		int ans=k; while(f[ans][k]<tt)++ans;printf("%d\n",ans);
	}
	return 0;
}