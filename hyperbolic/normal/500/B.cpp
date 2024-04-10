#include <stdio.h>
int x[310],a,check[310];
char y[310][310];
void func(int k, int target)
{
	int i;
	y[target][k]=y[k][target]='1';
	if(check[k]) return;
	check[k]=1;
	for(i=1;i<=a;i++)
	{
		if(y[k][i]=='1')
		{
			if(check[i]==0) func(i,target);
		}
	}
}
void clear()
{
	for(int i=1;i<=a;i++) check[i]=0;
}
int main()
{
	int i,j,t;
	scanf("%d",&a);
	for(i=1;i<=a;i++) scanf("%d",&x[i]);
	for(i=1;i<=a;i++) scanf("%s",y[i]+1);
	for(i=1;i<=a;i++)
	{
		func(i,i);
		clear();
	}
	for(i=1;i<=a;i++)
	{
		for(j=i+1;j<=a;j++)
		{
			if(y[i][j]=='1')
			{
				if(x[i]>x[j])
				{
					t=x[i];
					x[i]=x[j];
					x[j]=t;
				}
			}
		}
	}
	for(i=1;i<=a;i++) printf("%d ",x[i]);
}