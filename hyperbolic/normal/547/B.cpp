#include <stdio.h>
#include <algorithm>

int ans[200010];
int next[200010],size[200010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

std::pair<int,int> x[200010];
int check[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) next[i] = i;
	for(int i=1;i<=a;i++) size[i] = 1;
	for(int i=1;i<=a;i++) scanf("%d",&x[i].first);
	for(int i=1;i<=a;i++) x[i].second = i;
	std::sort(x+1,x+a+1);
	for(int i=a;i>=1;i--)
	{
		int k = x[i].second;
		check[k] = 1;
		if(k-1>=1 && check[k-1]==1)
		{
			int s = find(k-1);
			int t = find(k);
			if(s!=t)
			{
				next[s] = t;
				size[t] += size[s];
			}
		}
		if(k+1<=a && check[k+1]==1)
		{
			int s = find(k+1);
			int t = find(k);
			if(s!=t)
			{
				next[s] = t;
				size[t] += size[s];
			}
		}
		k = find(k);
		if(ans[size[k]]==0) ans[size[k]] = x[i].first;
	}
	for(int i=a;i>=1;i--)
	{
		ans[i] = ans[i]>ans[i+1]?ans[i]:ans[i+1];
	}
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}