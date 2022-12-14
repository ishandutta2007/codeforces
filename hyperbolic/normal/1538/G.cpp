#include <stdio.h>

long long int ans;
long long int a,b,c,d;
void func(long long int s, long long int t)
{
	for(int i=-2;i<=2;i++)
	{
		for(int j=-2;j<=2;j++)
		{
			long long int s2 = s+i, t2 = t+j;
			if(s2<0) continue;
			if(t2<0) continue;
			if(s2*c+t2*d <= a && s2*d + t2*c<= b) ans = ans>s2+t2?ans:s2+t2;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(c==d)
		{
			printf("%lld\n",a/c<b/c?a/c:b/c);
			continue;
		}
		
		func(a/c,0);
		func(b/d,0);
		func(0,a/d);
		func(0,b/c);
		long long int s = (a*c-b*d)/(c*c-d*d);
		long long int t = (a*d-b*c)/(d*d-c*c);
		//printf("%lld %lld!!\n",s,t);
		func(s,t);
		printf("%lld\n",ans);
	}
}