#include <stdio.h>

int ans[1010][1010],x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++) scanf("%d",&x[i]);
	for(int i=0;i<a;i++) for(int j=0;j<a;j++) ans[i][j] = (i*j)%a;
	for(int i=0;i<a;i++)
	{
		int val = x[i]-ans[i][i];
		val += a, val %= a;
		for(int j=0;j<a;j++) ans[i][j] += val;
	}
	for(int i=0;i<a;i++) for(int j=0;j<a;j++) ans[i][j] %= a;
	
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
}