#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int check[200010];
int count1[200010],count2[200010];

int func(int k)
{
	if(check[k]) return check[k];
	if(count1[k]<=1) return check[k] = 1;
	int ans = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(count2[V[k][i]]>=2)
		{
			int t = func(V[k][i]);
			ans = ans>t?ans:t;
		}
	}
	return check[k] = ans+1;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		count1[c]++;
		count2[d]++;
	}
	
	int ans = 1;
	for(int i=1;i<=a;i++)
	{
		int c = func(i);
		ans = ans>c?ans:c;
	}
	printf("%d",ans);
}