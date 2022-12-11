#include <bits/stdc++.h>
using namespace std;

const int MAXN=505;

bool f[MAXN][MAXN];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	f[0][0]=true;
	for (int i=0;i<n;i++)
	{
		int c;
		scanf("%d",&c);
		for (int j=k;j>=c;j--)
			for (int l=j;l>=0;l--)
			{
				f[j][l]=f[j][l]||f[j-c][l];
				if (l>=c) f[j][l]=f[j][l]||f[j-c][l-c];
			}
	}
	int cnt=0;
	for (int i=0;i<=k;i++)
		if (f[k][i])
			cnt++;
	printf("%d\n",cnt);
	for (int i=0;i<=k;i++)
		if (f[k][i])
			printf("%d ",i);
	return 0;
}