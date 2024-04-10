#include <stdio.h>
#include <map>

std::map<int,int> M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			M[b]++;
		}
		
		int s = 0;
		for(std::map<int,int> ::iterator it = M.begin();it!=M.end();it++)
		{
			int t = (it->second);
			s = s>t?s:t;
		}
		int t = a-s;
		if(s<=a-s) printf("%d\n",a%2);
		else printf("%d\n",a-(a-s)*2);
	}
}