#include <stdio.h>
#include <vector>

struct str{
	int first;
	int second;
	int index;
};
std::vector<str> V;
std::pair<int,int> query[200010];

int next[200010];
int size[200010];
int ans[200010];

void func(std::vector<str> &V, int L, int R)
{
	if(L>R) return;
	
	std::vector<int> save;
	int h = (L+R)/2;
	for(int i=L;i<=h;i++)
	{
		int s = query[i].first;
		int t = query[i].second;
		while(next[s]!=s) s = next[s];
		while(next[t]!=t) t = next[t];
		
		if(size[s]>size[t])
		{
			save.push_back(1);
			next[t] = s;
			size[s] += size[t];
		}
		else
		{
			save.push_back(2);
			next[s] = t;
			size[t] += size[s];
		}
	}
	std::vector<str> V1,V2;
	
	for(int i=0;i<V.size();i++)
	{
		int s = V[i].first;
		int t = V[i].second;
		while(next[s]!=s) s = next[s];
		while(next[t]!=t) t = next[t];
		if(s==t)
		{
			ans[V[i].index] = h;
			V1.push_back(V[i]);
		}
		else V2.push_back(V[i]);
	}
	
	func(V2,h+1,R);
	for(int i=h;i>=L;i--)
	{
		if(save[i-L]==1)
		{
			int s = query[i].first;
			while(next[s]!=s) s = next[s];
			int t = query[i].second;
			while(next[t]!=s) t = next[t];
			next[t] = t;
			size[s] -= size[t];
		}
		else
		{
			int t = query[i].second;
			while(next[t]!=t) t = next[t];
			int s = query[i].first;
			while(next[s]!=t) s = next[s];
			next[s] = s;
			size[t] -= size[s];
		}
	}
	func(V1,L,h-1);
}

int x[200010];
long long int sum[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++) if(x[i]!=x[i+1]) V.push_back({x[i],x[i+1],i});
	for(int i=1;i<=a;i++) next[i] = i;
	for(int i=1;i<=a;i++) size[i] = 1;
	
	for(int i=1;i<b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		query[i] = std::make_pair(c,d);
	}
	
	func(V,1,b-1);
	
	for(int i=1;i<a;i++)
	{
		sum[0]++;
		sum[ans[i]]--;
	}
	for(int i=1;i<a;i++) sum[i] += sum[i-1];
	for(int i=0;i<b;i++) printf("%lld\n",sum[i]);
}