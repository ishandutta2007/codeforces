#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==0&&b==0)
	{
		if(d==c-1)
		{
			printf("YES\n");
			for(int i=1;i<=d;i++) printf("2 3 ");
			printf("2");
		}
		else if(d==c)
		{
			printf("YES\n");
			for(int i=1;i<=d;i++) printf("2 3 ");
		}
		else if(d==c+1)
		{
			printf("YES\n");
			for(int i=1;i<=c;i++) printf("3 2 ");
			printf("3");
		}
		else printf("NO");
		return 0;
	}
	
	if(c==0&&d==0)
	{
		if(a==b-1)
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("1 0 ");
			printf("1");
		}
		else if(a==b)
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("1 0 ");
		}
		else if(a==b+1)
		{
			printf("YES\n");
			for(int i=1;i<=b;i++) printf("0 1 ");
			printf("0");
		}
		else printf("NO");
		return 0;
	}
	
	// start 0, end 0
	if(a>=2&&b>=2)
	{
		if(1)
		{
			int s = (b-2)-(a-2);
			if(s>=0 && s+d==c-1)
			{
				printf("YES\n");
				printf("0 1 ");
				for(int i=1;i<=a-2;i++) printf("0 1 ");
				for(int i=1;i<=(b-2)-(a-2);i++) printf("2 1 ");
				for(int i=1;i<=d;i++) printf("2 3 ");
				printf("2 1 0");
				return 0;
			}
		}
	}
	
	// start 0, else
	if(a>=1&&b>=1)
	{
		if(1)
		{
			int s = (b-1)-(a-1);
			if(s>=0 && s+d==c-1)
			{
				printf("YES\n");
				printf("0 1 ");
				for(int i=1;i<=a-1;i++) printf("0 1 ");
				for(int i=1;i<=(b-1)-(a-1);i++) printf("2 1 ");
				for(int i=1;i<=d;i++) printf("2 3 ");
				printf("2");
				return 0;
			}
			if(s>=0 && s+d==c)
			{
				printf("YES\n");
				printf("0 1 ");
				for(int i=1;i<=a-1;i++) printf("0 1 ");
				for(int i=1;i<=(b-1)-(a-1);i++) printf("2 1 ");
				for(int i=1;i<=d;i++) printf("2 3 ");
				return 0;
			}
		}
	}
	
	// else, else
	
	if(b>=a+1)
	{
		int s = b-a;
		if(s>=0 && s+d==c-1)
		{
			printf("YES\n");
			printf("2 ");
			for(int i=1;i<=a;i++) printf("1 0 ");
			printf("1 ");
			for(int i=1;i<=b-a-1;i++) printf("2 1 ");
			for(int i=1;i<=d;i++) printf("2 3 ");
			printf("2");
			return 0;
		}
		if(s>=0 && s+d==c)
		{
			printf("YES\n");
			printf("2 ");
			for(int i=1;i<=a;i++) printf("1 0 ");
			printf("1 ");
			for(int i=1;i<=b-a-1;i++) printf("2 1 ");
			for(int i=1;i<=d;i++) printf("2 3 ");
			return 0;
		}
		if(s>=0&&s+d==c+1)
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("1 0 ");
			printf("1 ");
			for(int i=1;i<=b-a-1;i++) printf("2 1 ");
			for(int i=1;i<=d;i++) printf("2 3 ");
			return 0;
		}
	}
	
	printf("NO");
}