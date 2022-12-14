#include <stdio.h>
#include <map>

std::map< std::pair<int,int> , int > check;
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int s= 0;
	for(int i=1;i<=a;i++) s+=x[i];
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		if(check[std::make_pair(c,d)]!=0)
		{
			x[check[std::make_pair(c,d)]]++;
			if(x[check[std::make_pair(c,d)]]>=1) s++;
		}
		check[std::make_pair(c,d)] = e;
		x[e]--;
		if(x[e]>=0) s--;
		printf("%lld\n",s);
	}
}