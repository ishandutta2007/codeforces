#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> R,B;
int x[200010];
char y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		B.clear();
		R.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		scanf("%s",y+1);
		
		for(int i=1;i<=a;i++)
		{
			if(y[i]=='R') R.push_back(x[i]);
			else B.push_back(x[i]);
		}
		std::sort(R.begin(),R.end());
		std::sort(B.begin(),B.end());
		
		for(int i=0;i<R.size();i++)
		{
			if(R[i]>a-(int)R.size()+i+1)
			{
				printf("NO\n");
				goto u;
			}
		}
		
		for(int i=0;i<B.size();i++)
		{
			if(B[i]<i+1)
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}