#include <stdio.h>
#include <vector>

std::vector<int> V1,V2;
int x[5010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) if(x[i]!=x[1]) goto u;
		printf("NO\n");
		continue;
		u:;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==x[1]) V1.push_back(i);
			else V2.push_back(i);
		}
		printf("YES\n");
		for(int i=0;i<V2.size();i++) printf("%d %d\n",V1[0],V2[i]);
		for(int i=1;i<V1.size();i++) printf("%d %d\n",V1[i],V2[0]);
	}
}