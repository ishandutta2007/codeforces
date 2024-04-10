#include <stdio.h>
#include <string.h>
#include <vector>

std::vector<int> V1,V0;
char x[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		V1.clear();
		V0.clear();
		for(int i=1;i<=a;i++)
		{
			if((x[i]-'0')%2==0) V0.push_back(x[i]-'0');
			else V1.push_back(x[i]-'0');
		}
		
		int s = 0, t = 0;
		while(1)
		{
			if(s==V0.size()&&t==V1.size()) break;
			else if(s==V0.size()) printf("%d",V1[t++]);
			else if(t==V1.size()) printf("%d",V0[s++]);
			else
			{
				if(V0[s]<V1[t]) printf("%d",V0[s++]);
				else printf("%d",V1[t++]);
			}
		}
		printf("\n");
	}
}