#include <stdio.h>

long long int MAX = 1;
int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		
		long long int ans = MAX;
		long long int s,t;
		
		if(b-e<d)
		{
			s = a+b-e-d;
			t = d;
			if(s<c) s = c;
			ans = ans<s*t?ans:s*t;
		}
		
		if(a-e<c)
		{
			s = c;
			t = a+b-e-c;
			if(t<d) t = d;
			ans = ans<s*t?ans:s*t;
		}
		
		s = a;
		t = (b-e);
		if(t<d) t = d;
		ans = ans<s*t?ans:s*t;
		
		s = a-e;
		t = b;
		if(s<c) s = c;
		ans = ans<s*t?ans:s*t;
		
		printf("%lld\n",ans);
	}
}