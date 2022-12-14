#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		int ans = 1234567890;
		scanf("%d%d",&a,&b);
		for(c=1;c*c<=b;c++);
		
		for(int i=0;i<=a&&i<=2*c;i++)
		{
			int d;
			if(b%(i+1)==0) d = i+(b/(i+1));
			else d = i+(b/(i+1))+1;
			ans = ans<d?ans:d;
		}
		if(ans<=a) printf("YES\n");
		else printf("NO\n");
	}
}