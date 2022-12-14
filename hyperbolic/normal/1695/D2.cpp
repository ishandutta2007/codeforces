#include <stdio.h>
#include <vector>

int ans;
int count[200010],prev[200010];
std::vector<int> V[200010];
void init(int k, int p)
{
	prev[k] = p;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		init(V[k][i],k);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) count[i] = 0;
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		int max = 0;
		for(int i=1;i<=a;i++) max = max>V[i].size()?max:V[i].size();
		
		if(a==1)
		{
			printf("0\n");
			continue;
		}
		else if(max==2)
		{
			printf("1\n");
			continue;
		}
		
		int root = 1;
		for(int i=1;i<=a;i++) if(V[i].size()>=3) root = i;
		init(root,0);
		
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()==1)
			{
				int t = i;
				while(V[t].size()<=2&&t!=root) t = prev[t];
				count[t]++;
			}
		}
		
		int ans = 0;
		for(int i=1;i<=a;i++) if(count[i]>=1) ans += (count[i]-1);
		printf("%d\n",ans);
	}
}