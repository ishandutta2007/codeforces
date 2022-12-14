#include <stdio.h>
#include <set>

std::multiset<int> S1,S2;

char x[10];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%s",x+1);
		scanf("%d%d",&b,&c);
		if(b>c)
		{
			int d = b;
			b = c;
			c= d;
		}
		if(x[1]=='+')
		{
			S1.insert(b);
			S2.insert(c);
		}
		else
		{
			std::multiset<int> ::iterator it1,it2;
			it1 = S1.end(), it1--;
			it2 = S2.end(), it2--;
			if((*it1)<=b&&(*it2)<=c) printf("YES\n");
			else printf("NO\n");
		}
	}
}