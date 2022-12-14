#include <stdio.h>
#include <vector>
#define MOD 1000000007

int check[500010];
int next[500010];

int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

std::vector<int> ans;
int power[500010];
int main()
{
	power[0] = 1;
	for(int i=1;i<=500000;i++) power[i] = (2*power[i-1])%MOD;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) next[i] = i;
	
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		if(c==1)
		{
			int d;
			scanf("%d",&d);
			d = find(d);
			if(check[d]==0)
			{
				check[d] = 1;
				ans.push_back(i);
			}
		}
		else
		{
			int d,e;
			scanf("%d%d",&d,&e);
			d = find(d);
			e = find(e);
			if(d==e) continue;
			if(check[d]==1&&check[e]==1) continue;
			next[d] = e;
			check[e] = check[e]>check[d]?check[e]:check[d];
			ans.push_back(i);
		}
	}
	
	printf("%d %d\n",power[ans.size()], ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}