#include <stdio.h>

int a,b;
int func(int s, int t, int type)
{
	int ans = 0;
	int C = 1;
	for(int i=0;i<20;i++)
	{
		int s2 = s%b;
		int t2 = t%b;
		ans += C*((s2+t2*type+b)%b);
		C*=b;
		s /= b, t /= b;
	}
	return ans;
}

int getQuery(int k)
{
	printf("%d\n",k);
	fflush(stdout);
	
	int c;
	scanf("%d",&c);
	return c;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		
		int s = 0 , t = 1;
		for(int i=0;i<a;i++)
		{
			int k = func(s,i,t);
			int c = getQuery(k);
			if(c==1) goto u;
			
			s = func(k,s,-1);
			t *= -1;
		}
		u:;
	}
}