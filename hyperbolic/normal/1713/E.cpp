#include <stdio.h>

int x[1010][1010],ans[1010][1010];
int next[2010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
		
		for(int i=1;i<=2*a;i++) next[i] = i;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				int s,t;
				s = i, t = j;
				if(find(s)==find(t))
				{
					ans[i][j] = x[i][j];
					continue;
				}
				s = i, t = j+a;
				if(find(s)==find(t))
				{
					ans[i][j] = x[j][i];
					continue;
				}
				
				if(x[i][j]<x[j][i])
				{
					ans[i][j] = x[i][j];
					next[find(i)] = find(j);
					next[find(i+a)] = find(j+a);
				}
				else if(x[i][j]>x[j][i])
				{
					ans[i][j] = x[j][i];
					next[find(i)] = find(j+a);
					next[find(i+a)] = find(j);
				}
				else ans[i][j] = x[i][j];
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++) printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
}