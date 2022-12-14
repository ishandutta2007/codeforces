#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

int x[200010],y[200010];
int z[400010];
int count[400010];
long long int sum[400010];
std::vector<int> index;
std::map<int,int> hash;

int next[400010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

struct str{
	int x0;
	int y0;
	int z0;
};
bool cmp(str a, str b)
{
	if(a.y0==b.y0) return a.x0<b.x0;
	return a.y0<b.y0;
}
std::vector<str> event;

long long int ans2[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++) index.push_back(x[i]);
	for(int i=1;i<=a;i++) ans += x[i];
	
	for(int i=1;i<=b;i++) index.push_back(y[i]);
	std::sort(index.begin(),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	for(int i=1;i<=a;i++) count[hash[x[i]]]++;
	for(int i=0;i<index.size();i++) z[i+1] = index[i];
	for(int i=1;i<=a+b;i++) sum[i] = sum[i-1]+z[i];
	for(int i=1;i<=a+b;i++) next[i] = i;
	
	
	for(int i=1;i<a+b;i++) event.push_back({1,z[i+1]-z[i],i});
	
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		event.push_back({2,d,i});
	}
	
	std::sort(event.begin(),event.end(),cmp);
	
	for(int i=0;i<event.size();i++)
	{
		if(event[i].x0==1)
		{
			int t = event[i].z0;
			int v = find(t+1);
			ans -= (sum[t]-sum[t-count[t]]);
			ans -= (sum[v]-sum[v-count[v]]);
			next[t] = v;
			count[v] += count[t];
			count[t] = 0;
			ans += (sum[v]-sum[v-count[v]]);
		}
		else ans2[event[i].z0] = ans;
	}
	
	for(int i=1;i<=c;i++) printf("%lld\n",ans2[i]);
}