#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int c = a, d = 0;
		while(c%b==0) c/=b, d++;
		if(d<=1) printf("NO\n");
		else
		{
			int count1 = 1;
			for(int i=2;i*i<=c;i++) if(c%i==0) count1++;
			if(count1>=2) printf("YES\n");
			else if(d==2) printf("NO\n");
			else
			{
				if(c>1)
				{
					int C = 0, b2 = b;
					while(b2%c==0) b2/=c, C++;
					if(d==3 && C==2)
					{
						printf("NO\n");
						continue;
					}
				}
				
				int count2 = 0;
				for(int i=2;i*i<=b;i++) if(b%i==0) count2++;
				if(count2>=1) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
}