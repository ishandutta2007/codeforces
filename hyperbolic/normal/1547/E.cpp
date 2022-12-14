#include <stdio.h>
#include <queue>

struct str{
	int first;
	int second;
};
bool operator<(str a, str b)
{
	return a.first>b.first;
}
std::priority_queue<str> Q;

int check[300010];
int x[300010],y[300010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		for(int i=1;i<=b;i++) scanf("%d",&y[i]);
		for(int i=1;i<=b;i++) Q.push({y[i],x[i]});
		
		for(int i=1;i<=a;i++) check[i] = 0;
		while(!Q.empty())
		{
			str t = Q.top();
			Q.pop();
			if(check[t.second]) continue;
			check[t.second] = t.first;
			
			if(t.second-1>=1) Q.push({t.first+1,t.second-1});
			if(t.second+1<=a) Q.push({t.first+1,t.second+1});
		}
		
		for(int i=1;i<=a;i++) printf("%d ",check[i]);
		printf("\n");
	}
}