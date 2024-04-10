#include <stdio.h>
#include <map>

std::map< std::pair<char,char> , int > count;

char x[100010],y[100010];
std::pair<char,char> P[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count.clear();
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]<y[a-i+1]) P[i] = std::make_pair(x[i],y[a-i+1]);
			else P[i] = std::make_pair(y[a-i+1],x[i]);
		}
		
		int C = 0;
		std::pair<char,char> check;
		for(int i=1;i<=a;i++) count[P[i]]++;
		for(std::map< std::pair<char,char> , int> ::iterator it = count.begin();it!=count.end();it++)
		{
			if((it->second)%2==1)
			{
				C++;
				check = (it->first);
			}
		}
		if(C==0) printf("YES\n");
		else if(C==1)
		{
			if(check.first==check.second) printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
}