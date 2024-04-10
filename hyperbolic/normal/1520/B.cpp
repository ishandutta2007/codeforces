#include <stdio.h>
#include <vector>

std::vector<int> V;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		while(a)
		{
			V.push_back(a%10);
			a/=10;
		}
		
		int s = 9*(V.size()-1);
		for(int i=V.size()-1;i>=0;i--)
		{
			if(V[i]>V.back())
			{
				printf("%d\n",s+V.back());
				goto u;
			}
			if(V[i]<V.back())
			{
				printf("%d\n",s+V.back()-1);
				goto u;
			}
		}
		printf("%d\n",s+V.back());
		u:;
	}
}