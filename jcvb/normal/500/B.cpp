#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int n;
int a[305][305];
int ok[305][305]={0};
int p[305];
int ans[305];
int off[305]={0};
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)	{
		for (int j=1;j<=n;j++){
			char c;while((c=getchar())<'0'||c>'1');
			a[i][j]=c-'0';
		}
		a[i][i]=1;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)a[i][j]|=a[i][k]&&a[k][j];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)ok[p[i]][j]|=a[i][j];
	}

	for (int i=1;i<=n;i++){
		int mi=0;
		for (int j=1;j<=n;j++)if(!off[j] && ok[j][i]){mi=j;break;}
		off[mi]=1;
		ans[i]=mi;
	}
	for (int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}