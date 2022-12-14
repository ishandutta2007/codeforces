#include <stdio.h>

int next[300010][30];
int find(int v, int k)
{
	for(int j=20;j>=0;j--)
	{
		if(k>=(1<<j))
		{
			v = next[v][j];
			k -= (1<<j);
		}
	}
	return v;
}

int left[300010],price[300010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	left[0] = b, price[0] = c;
	for(int i=1;i<=a;i++)
	{
		int d;
		scanf("%d",&d);
		if(d==1)
		{
			int e,f,g;
			scanf("%d%d%d",&e,&f,&g);
			next[i][0] = e;
			left[i] = f, price[i] = g;
			for(int j=1;j<=20;j++) next[i][j] = next[next[i][j-1]][j-1];
		}
		else
		{
			int e,f;
			scanf("%d%d",&e,&f);
			int f2 = f;
			long long int ans = 0;
			int v = e;
			int h = 0;
			for(int j=20;j>=0;j--)
			{
				int t = next[v][j];
				if(left[t]>0) h += (1<<j), v = next[v][j];
			}
			for(int j=h;j>=0;j--)
			{
				int t = find(e,j);
				if(left[t]<f)
				{
					ans += (long long int)price[t]*left[t];
					f -= left[t];
					left[t] = 0;
				}
				else
				{
					ans += (long long int)price[t]*f;
					left[t] -= f;
					f = 0;
					break;
				}
			}
			printf("%d %lld\n",f2-f,ans);
			fflush(stdout);
		}
	}
}