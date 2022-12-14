#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX 1234567890

int max(int s, int t)
{
	return s>t?s:t;
}

long long int dist2[410][410],dist3[410][410];
long long int dist[410][410];
void func(int start, int L, int R, int l, int r)
{
	if(L>R) return;
	
	int h = (L+R)/2;
	dist3[start][h] = MAX;
	int opt = -1;
	for(int i=l;i<=r&&i<=h;i++)
	{
		if(dist3[start][h]>max(dist2[start][i],dist[i][h]))
		{
			opt = i;
			dist3[start][h] = max(dist2[start][i],dist[i][h]);
		}
	}
	func(start,L,h-1,l,opt);
	func(start,h+1,R,opt,r);
	
}

struct str{
	int first;
	int second;
	int c;
	int r;
};
bool cmp(str a, str b)
{
	return a.r<b.r;
}
std::vector<str> query;

int x[410];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int start=1;start<=a;start++) for(int end=start+1;end<=a;end++) dist2[start][end] = dist[start][end] = x[end] - x[start];
	
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		int c,d,e,f;
		scanf("%d%d%d%d",&c,&d,&e,&f);
		query.push_back({c,d,e,f});
	}
	std::sort(query.begin(),query.end(),cmp);
	
	int k = 1;
	for(int i=0;i<query.size();i++)
	{
		for(int j=k;j<=query[i].r;j++)
		{
			for(int start=1;start<=a;start++) func(start,start+1,a,start,a);
			for(int start=1;start<=a;start++)
			{
				for(int end=start+1;end<=a;end++)
				{
					dist2[start][end] = dist3[start][end];
				}
			}
		}
		k = query[i].r+1;
		long long int s = dist2[query[i].first][query[i].second]*query[i].c;
		ans = ans>s?ans:s;
	}
	printf("%lld",ans);
}