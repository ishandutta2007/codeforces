#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
int x[maxn], y[maxn];
multiset<pair<int, int> > stx, sty; 
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
long long dis[maxn];
bool vis[maxn];

int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &x[m + 1], &y[m + 1], &x[m + 2], &y[m + 2]);
	for(int i = 1;i <= m;i++) scanf("%d%d", &x[i], &y[i]);
	for(int i = 1;i <= m + 1;i++){
		stx.insert({x[i], i}), sty.insert({y[i], i});
	}
	memset(dis, 0x3f, sizeof(dis));
	q.push({0, m + 1}), dis[m + 1] = 0;
	while(!q.empty()){
		int i = q.top().second;q.pop();
		if(vis[i]) continue;
		//printf("%d %lld--\n", i, dis[i]);
		vis[i] = true;
		stx.erase(stx.find({x[i], i})), sty.erase(sty.find({y[i], i}));
		multiset<pair<int, int> >::iterator it = stx.lower_bound({x[i], 0});
		if(it != stx.end()){
			int co = abs(x[i] - (it->first)), to = it->second;
			if(dis[to] > dis[i] + co) dis[to] = dis[i] + co, q.push({dis[to], to});
		}
		if(it != stx.begin()){
			--it;
			int co = abs(x[i] - (it->first)), to = it->second;
			if(dis[to] > dis[i] + co) dis[to] = dis[i] + co, q.push({dis[to], to});
		}
		it = sty.lower_bound({y[i], 0});
		if(it != sty.end()){
			int co = abs(y[i] - (it->first)), to = it->second;
			if(dis[to] > dis[i] + co) dis[to] = dis[i] + co, q.push({dis[to], to});
		}
		if(it != sty.begin()){
			--it;
			int co = abs(y[i] - (it->first)), to = it->second;
			if(dis[to] > dis[i] + co) dis[to] = dis[i] + co, q.push({dis[to], to});
		}
	}
	long long ans = 1e18;
	for(int i = 1;i <= m + 1;i++) ans = min(ans, abs(x[i] - x[m + 2]) + abs(y[i] - y[m + 2]) + dis[i]);
	printf("%lld", ans);
	 
}