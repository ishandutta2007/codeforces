#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	long long int x0;
	long long int y0;
	int ind;
}x[110];
bool cmp(str a, str b)
{
	return a.y0<b.y0;
}

long long int MAX = 1;
int a,b;
int next[110][110][110];
long long int check[110][110][110];
long long int func(int s, int t, int u)
{
	if(s>a)
	{
		if(t==b) return x[u].x0;
		else return -MAX;
	}
	if(check[s][t][u]!=-1) return check[s][t][u];
	
	long long int s1;
	if(x[s].x0 > x[u].x0) s1 = func(s+1,t,s) + (b-1)*x[s].y0;
	else s1 = func(s+1,t,u) + (b-1)*x[s].y0;
	
	if(t>=b)
	{
		next[s][t][u] = -1;
		return check[s][t][u] = s1;
	}
	
	long long int s2 = func(s+1,t+1,u) + (t-1)*x[s].y0 + x[s].x0;
	
	//printf("%d : %lld %lld!!\n",s,s1,s2);
	
	if(s1>s2) next[s][t][u] = -1;
	else next[s][t][u] = 1;
	return check[s][t][u] = s1>s2?s1:s2;
}

int check2[110];
int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) for(int k=0;k<=a+1;k++) check[i][j][k] = -1,next[i][j][k] = 0;
		for(int i=1;i<=a;i++) scanf("%d%d",&x[i].x0,&x[i].y0);
		for(int i=1;i<=a;i++) x[i].ind = i;
		std::sort(x+1,x+a+1,cmp);
		x[0].x0 = 0;
		
		func(1,1,0);
		
		printf("%d\n",(b-1)+(a-b)*2+1);
		
		for(int i=1;i<=a;i++) check2[i] = 0;
		int s0 = 1, t0 = 1, u0 = 0;
		for(int i=1;i<=a;i++)
		{
			if(next[s0][t0][u0]==1)
			{
				check2[s0] = 1;
				printf("%d ",x[s0].ind);
				s0 = s0+1, t0 = t0+1, u0 = u0;
			}
			else
			{
				if(x[s0].x0 > x[u0].x0) s0 = s0+1, t0 = t0, u0 = s0-1;
				else s0 = s0+1, t0 = t0, u0 = u0;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(check2[i]==1) continue;
			if(i==u0) continue;
			printf("%d %d ",x[i].ind,-x[i].ind);
		}
		if(u0>0) printf("%d\n",x[u0].ind);
	}
}