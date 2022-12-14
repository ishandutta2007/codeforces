#include <stdio.h>

int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		
		int ans = 0;
		while(a>=2)
		{
			if(b==0&&c==0) break;
			else if(b==0) a-=2, c--, ans+=e;
			else if(c==0) a-=2, b--, ans+=d;
			else
			{
				if(d>=e) a-=2, b--, ans+=d;
				else a-=2, c--, ans+=e;
			}
		}
		printf("%d\n",ans);
	}
}