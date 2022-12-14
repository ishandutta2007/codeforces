#include <stdio.h>

int next[31][100010],value[31][100010],possible[31][100010];
int find(int s, int t)
{
	if(next[s][t]==t) return t;
	else return next[s][t] = find(s,next[s][t]);
}

struct str{
	int first;
	int second;
	int value;
}edge[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		edge[i] = {c,d,e};
	}
	
	for(int i=0;i<30;i++)
	{
		for(int j=1;j<=a;j++) next[i][j] = j;
		for(int j=1;j<=b;j++)
		{
			if(((edge[j].value>>i)&1)==1)
			{
				int s = edge[j].first, t = edge[j].second;
				next[i][find(i,s)] = next[i][find(i,t)];
			}
		}
	}
	
	for(int i=0;i<30;i++)
	{
		for(int j=1;j<=a;j++) value[i][j] = 1e30 - 1;
		for(int j=1;j<=b;j++)
		{
			if(((edge[j].value>>i)&1)==1)
			{
				int s = edge[j].first, t = edge[j].second;
				int s2 = find(i,s), t2 = find(i,t);
				if(s2==t2) value[i][s2] &= edge[j].value;
			}
		}
	}
	
	for(int i=0;i<30;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(((edge[j].value>>i)&1)==0)
			{
				int s = edge[j].first, t = edge[j].second;
				int s2 = find(i,s), t2 = find(i,t);
				if(s2!=t2)
				{
					if((value[i][s2]&edge[j].value)==0) possible[i][s2] = 1;
					if((value[i][t2]&edge[j].value)==0) possible[i][t2] = 1;
				}
			}
		}
	}
	
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		for(int i=0;i<30;i++)
		{
			int s = find(i,d), t = find(i,e);
			if(s==t)
			{
				printf("0\n");
				goto u;
			}
		}
		
		for(int i=1;i<30;i++)
		{
			if(possible[i][find(i,d)]==1)
			{
				printf("1\n");
				goto u;
			}
		}
		printf("2\n");
		
		u:;
	}
}