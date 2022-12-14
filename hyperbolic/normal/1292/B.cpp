#include <stdio.h>
#include <vector>
long long int abs(long long int k)
{
	return k>0?k:-k;
}

std::pair<long long int, long long int> P[100010];
long long int MAX = 2;
int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	
	long long int a,b,c,d,e,f;
	scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
	
	long long int x0, y0, t;
	scanf("%lld%lld%lld",&x0,&y0,&t);
	
	long long int x1 = a, y1 = b;
	int p = 0;
	P[p++] = std::make_pair(x1,y1);
	
	while(1)
	{
		long long int x2 = c*x1+e;
		long long int y2 = d*y1+f;
		if(x2>MAX) break;
		if(y2>MAX) break;
		x1 = x2, y1 = y2;
		P[p++] = std::make_pair(x1,y1);
	}
	
	int ans = 0;
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<p;j++)
		{
			if(abs(x0-P[i].first)+abs(y0-P[i].second)+abs(P[i].first-P[j].first)+abs(P[i].second-P[j].second)<=t)
			{
				ans = ans>abs(i-j)+1?ans:abs(i-j)+1;
			}
		}
	}
	printf("%d",ans);
}