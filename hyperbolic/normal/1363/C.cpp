#include <stdio.h>
#include <vector>

std::vector<int> V[1010];

int func(int k, int prev)
{
	int s = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		s += func(V[k][i],k);
	}
	return s;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		if(a<=2)
		{
			printf("Ayush\n");
			continue;
		}
		
		if(V[b].size()==1)
		{
			printf("Ayush\n");
			continue;
		}
		
		int C1=0, C2=0;
		for(int i=0;i<V[b].size();i++)
		{
			if(func(V[b][i],b)%2==1) C1++;
			else C2++;
		}
		
		if(C2>=1)
		{
			if(C1>=1)
			{
				if(C1%2==1) printf("Ayush\n");
				else printf("Ashish\n");
			}
			else printf("Ashish\n");
		}
		else
		{
			if(C1%2==1) printf("Ayush\n");
			else printf("Ashish\n");
		}
	}
}