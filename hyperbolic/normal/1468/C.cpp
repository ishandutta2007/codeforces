#include <stdio.h>
#include <queue>

struct str{
	int first;
	int second;
};
bool operator<(str a, str b)
{
	if(a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}
std::priority_queue<str> Q1;
std::queue<str> Q2;

int check[500010];
int main()
{
	int T;
	scanf("%d",&T);
	int p = 1;
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			int b;
			scanf("%d",&b);
			Q1.push({b,p});
			Q2.push({b,p});
			p++;
		}
		if(a==2)
		{
			while(1)
			{
				str P = Q2.front();
				if(check[P.second]==0)
				{
					check[P.second] = 1;
					printf("%d\n",P.second);
					break;
				}
				else Q2.pop();
			}
		}
		if(a==3)
		{
			while(1)
			{
				str P = Q1.top();
				if(check[P.second]==0)
				{
					check[P.second] = 1;
					printf("%d\n",P.second);
					break;
				}
				else Q1.pop();
			}
		}
	}
}