#include <stdio.h>
#include <queue>
struct str{
	int x0;
	int y0;
};
std::queue<str> Q2;
std::queue<int> Q[300010];
int main()
{
	int a,b,c,d,s=1,count=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d",&d);
			
			str A;
			A.x0 = d;
			A.y0 = s;
			Q2.push(A);
			Q[d].push(s);
			s++;
			count++;
		}
		else if(c==2)
		{
			scanf("%d",&d);
			while(!Q[d].empty())
			{
				Q[d].pop();
				count--;
			}
		}
		else if(c==3)
		{
			scanf("%d",&d);
			while(!Q2.empty())
			{
				int t1 = Q2.front().x0;
				int t2 = Q2.front().y0;
				if(t2>d) break;
				if(!Q[t1].empty())
				{
					if(Q[t1].front()<=d)
					{
						Q[t1].pop();
						count--;
					}
				}
				Q2.pop();
			}
		}
		printf("%d\n",count);
	}
}