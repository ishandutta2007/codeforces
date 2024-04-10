#include <stdio.h>
#include <map>
int x[510];
int a;
std::map<int,int> check[510][510];
int func(int s, int t, int prev)
{
	if(s>a) return 0;
	if(check[s][t].find(prev)!=check[s][t].end()) return check[s][t][prev];
	
	int s1=1000,s2=1000;
	if(prev<=x[s]) s1 = func(s+1,t,x[s]);
	if(prev<=t&&x[s]>t) s2 = func(s+1,x[s],t)+1;
	return check[s][t][prev] = s1<s2?s1:s2;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<=500;j++)
			{
				check[i][j].clear();
			}
		}
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int t = func(1,b,0);
		if(t>=1000) printf("-1\n");
		else printf("%d\n",t);
	}
}