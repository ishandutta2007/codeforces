#include <stdio.h>

int valid[20];
int main()
{
	valid[0] = 0, valid[1] = 1, valid[2] = 5, valid[3] = -1, valid[4] = -1, valid[5] = 2, valid[6] = -1, valid[7] = -1, valid[8] = 8, valid[9] = -1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d",&a,&b);
		scanf("%d:%d",&c,&d);
		while(1)
		{
			int c1 = c/10;
			int c2 = c%10;
			int d1 = d/10;
			int d2 = d%10;
			if(valid[c1]==-1  || valid[c2]==-1 || valid[d1] == -1 || valid[d2]==-1)
			{
				d++;
				if(d==b) c++, d-=b;
				if(c==a) c-=a;
			}
			else
			{
				int d3 = 10*valid[c2]+valid[c1];
				int c3 = 10*valid[d2]+valid[d1];
				if(c3<a && d3<b)
				{
					printf("%02d:%02d\n",c,d);
					break;
				}
				else
				{
					d++;
					if(d==b) c++, d-=b;
					if(c==a) c-=a;
				}
			}
		}
	}
}