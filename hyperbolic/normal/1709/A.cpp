#include <stdio.h>
#include <vector>
#include <algorithm>
int next[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		next[1] = b;
		next[2] = c;
		next[3] = d;
		std::vector<int> V;
		V.push_back(a);
		V.push_back(next[a]);
		V.push_back(next[next[a]]);
		std::sort(V.begin(),V.end());
		for(int i=0;i<V.size();i++)
		{
			if(V[i]==0)
			{
				printf("NO\n");
				goto u;
			}
		}
		if(V.size()!=3)
		{
			printf("NO\n");
			goto u;
		}
		if(V[0]==V[1])
		{
			printf("NO\n");
			goto u;
		}
		if(V[1]==V[2])
		{
			printf("NO\n");
			goto u;
		}
		printf("YES\n");
		u:;
	}
}