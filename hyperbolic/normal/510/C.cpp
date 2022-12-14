#include <stdio.h>
#include <string.h>
char x[110][110];
int value[110],dist[30][30];
int check[30],ans[30],control,number=26;
void func(int k)
{
	int i;
	if(control) return;
	if(check[k]==1)
	{
		control=1;
		return;
	}
	if(check[k]==2) return;
	check[k]=1;
	for(i=0;i<26;i++)
	{
		if(dist[k][i]==1) func(i);
	}
	ans[number--]=k;
	check[k]=2;
}
int main()
{
	int a,b,c,i,j,k;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%s",x[i]+1);
		value[i]=strlen(x[i]+1);
	}
	for(i=1;i<=a;i++)
	{
		for(j=i+1;j<=a;j++)
		{
			for(k=1;k<=value[i];k++)
			{
				if(k>value[j])
				{
					printf("Impossible");
					return 0;
				}
				if(x[i][k]!=x[j][k])
				{
					b=x[i][k]-'a';
					c=x[j][k]-'a';
					if(dist[b][c]==-1)
					{
						printf("Impossible");
						return 0;
					}
					dist[b][c]=1;
					dist[c][b]=-1;
					break;
				}
			}
		}
	}
	for(i=0;i<26;i++) func(i);
	if(control)
	{
		printf("Impossible");
		return 0;
	}
	for(i=1;i<=26;i++) printf("%c",ans[i]+'a');
}