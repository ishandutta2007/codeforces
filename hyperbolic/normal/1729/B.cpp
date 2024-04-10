#include <stdio.h>
#include <vector>
#include <algorithm>

char x[100010];
std::vector<char> ans;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) x[i] -= '0';
		
		int p = a;
		while(p>=1)
		{
			int val;
			if(x[p]==0)
			{
				val = 10*x[p-2]+x[p-1];
				p-=3;
			}
			else
			{
				val = x[p];
				p--;
			}
			ans.push_back('a'+val-1);
		}
		std::reverse(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
		printf("\n");
	}
}