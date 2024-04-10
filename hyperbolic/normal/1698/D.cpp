#include <stdio.h>
#include <vector>

std::vector<int> V;
void getQuery(int s, int t)
{
	V.clear();
	printf("? %d %d\n",s,t);
	fflush(stdout);
	
	for(int i=s;i<=t;i++)
	{
		int a;
		scanf("%d",&a);
		V.push_back(a);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int min = 1, max = a;
		while(min<max)
		{
			int h = (min+max)/2;
			getQuery(min,h);
			
			int C = 0;
			for(int i=0;i<V.size();i++) if(min<=V[i]&&V[i]<=h) C++;
			if(C%2==1) max = h;
			else min = h+1;
		}
		printf("! %d\n",min);
		fflush(stdout);
	}
}