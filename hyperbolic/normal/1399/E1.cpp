#include <stdio.h>
#include <queue>
#include <vector>

struct str{
	long long int diff;
	long long int value;
	int size;
};
bool operator<(str a, str b)
{
	if(a.diff==b.diff) return a.value<b.value;
	return a.diff<b.diff;
}
std::priority_queue<str> Q;
long long int ans = 0;
std::vector< std::pair<int,long long int> > V[200010];
int func(int k, int parent)
{
	int size = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==parent) continue;
		size += func(V[k][i].first,k);
	}
	if(size==0) size++;
		
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==parent)
		{
			ans += (long long int)V[k][i].second * size;
			long long int t = V[k][i].second - (V[k][i].second/2);
			Q.push({t*size,V[k][i].second,size});
		}
	}
	return size;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		while(!Q.empty()) Q.pop();
		
		int a;
		long long int b;
		scanf("%d%lld",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			V[c].push_back(std::make_pair(d,e));
			V[d].push_back(std::make_pair(c,e));
		}
		
		func(1,0);
		if(ans<=b)
		{
			printf("0\n");
			continue;
		}
		
		for(int i=1;;i++)
		{
			str A = Q.top();
			Q.pop();
			ans -= A.diff;
			if(ans<=b)
			{
				printf("%d\n",i);
				goto u;
			}
			long long int s = A.value/2;
			long long int t = s - (s/2);
			Q.push({t*A.size,s,A.size});
		}
		u:;
	}
}