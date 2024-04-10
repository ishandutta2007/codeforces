#include <stdio.h>
#include <algorithm>

struct str{
	int first;
	int second;
	int index;
	int answer;
}P[100010];
bool cmp1(str a, str b)
{
	return a.first<b.first;
}
bool cmp2(str a, str b)
{
	return a.index<b.index;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			P[i]={b,c,i,0};
		}
		std::sort(P+1,P+a+1,cmp1);
		
		P[1].answer = 1;
		int limit = P[1].second;
		int control = 0;
		for(int i=2;i<=a;i++)
		{
			if(P[i].first<=limit)
			{
				P[i].answer = 1;
				limit = limit>P[i].second?limit:P[i].second;
			}
			else
			{
				for(int j=i;j<=a;j++) P[j].answer = 2;
				control = 1;
				break;
			}
		}
		
		if(control==0) printf("-1\n");
		else
		{
			std::sort(P+1,P+a+1,cmp2);
			for(int i=1;i<=a;i++) printf("%d ",P[i].answer);
			printf("\n");
		}
	}
}