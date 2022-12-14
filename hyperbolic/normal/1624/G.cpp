#include <stdio.h>
#include <vector>

struct str{
	int first;
	int second;
	int value;
};
std::vector<str> edge,temp;

int next[200010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		edge.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			edge.push_back({c,d,e});
		}
		
		long long int ans = 0;
		for(int i=30;i>=0;i--)
		{
			for(int j=1;j<=a;j++) next[j] = j;
			for(int j=0;j<edge.size();j++)
			{
				if(((edge[j].value>>i)&1)==0)
				{
					int s = find(edge[j].first);
					int t = find(edge[j].second);
					next[s] = t;
				}
			}
			
			int control = 0;
			for(int j=2;j<=a;j++) if(find(1)!=find(j)) control = 1;
			
			if(control==1) ans += (1<<i);
			else
			{
				temp.clear();
				for(int j=0;j<edge.size();j++) if(((edge[j].value>>i)&1)==0) temp.push_back(edge[j]);
				edge.clear();
				for(int j=0;j<temp.size();j++) edge.push_back(temp[j]);
			}
		}
		printf("%lld\n",ans);
	}
}