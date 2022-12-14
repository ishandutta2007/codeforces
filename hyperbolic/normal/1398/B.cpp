#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

std::vector<int> V;
char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		scanf("%s",x+1);
		int a = strlen(x+1);
		x[0] = '0', x[a+1] = '0';
		int start = 0;
		for(int i=1;i<=a+1;i++)
		{
			if(x[i-1]=='0') start = i;
			if(x[i]=='0') V.push_back(i-start);
		}
		std::sort(V.begin(),V.end());
		
		int ans = 0;
		for(int i=V.size()-1;i>=0;i-=2) ans += V[i];
		printf("%d\n",ans);
	}
}