#include <stdio.h>
#include <string.h>
#include <vector>

std::vector<int> V;
char x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) if(x[i]!=x[i-1]) V.push_back(i);
		
		if(V.size()%2==1)
		{
			for(int i=1;i<=a;i++) printf("%c",x[i]);
			printf("\n");
		}
		else
		{
			for(int i=1;i<a;i++) printf("%c",x[i]);
			printf("%c",'a'+'b'-x[a]);
			printf("\n");
		}
	}
}