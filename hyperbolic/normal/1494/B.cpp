#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		for(int i1=0;i1<=1;i1++)
		{
			for(int i2=0;i2<=1;i2++)
			{
				for(int i3=0;i3<=1;i3++)
				{
					for(int i4=0;i4<=1;i4++)
					{
						if(b<i1+i2) continue;
						if(c<i2+i3) continue;
						if(d<i3+i4) continue;
						if(e<i4+i1) continue;
						if(b>a-2+i1+i2) continue;
						if(c>a-2+i2+i3) continue;
						if(d>a-2+i3+i4) continue;
						if(e>a-2+i4+i1) continue;
						printf("YES\n");
						goto v;
					}
				}
			}
		}
		printf("NO\n");
		v:;
	}
}