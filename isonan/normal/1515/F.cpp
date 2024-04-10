#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

int n,m,x;
int f[300001],u[300001],v[300001];
long long a[300001];
std::vector<std::pair<int,int> >edge[300001];
std::priority_queue<std::pair<long long,int> >heap;
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	long long sum=0;
	for(int i=1;i<=n;++i)scanf("%lld",a+i),sum+=a[i];
	if(sum<1ll*(n-1)*x){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		edge[u].push_back(std::make_pair(v,i));
		edge[v].push_back(std::make_pair(u,i));
		::u[i]=u;
		::v[i]=v;
	}
	for(int i=1;i<=n;++i)heap.push(std::make_pair(a[i],i));
	for(int cnt=0;!heap.empty();){
		long long Sum=heap.top().first;
		int now=heap.top().second;
		heap.pop();
		if(find(now)!=now)continue;
		if(Sum!=a[now])continue;
		++cnt;
		int s,t;
		for(;;){
			std::pair<int,int>tem=edge[now].back();
			if(find(tem.first)==now)edge[now].pop_back();
			else{
				s=now;
				t=find(tem.first);
				printf("%d\n",tem.second);
				break;
			}
		}
		if(edge[s].size()>edge[t].size())std::swap(s,t);
		f[s]=t;
		a[t]+=a[s]-::x;
		for(int i=0;i<edge[s].size();++i){
			if(find(edge[s][i].first)!=t){
				edge[t].push_back(edge[s][i]);
			}
		}
		heap.push(std::make_pair(a[t],t));
		if(cnt==n-1)break;
	}
}