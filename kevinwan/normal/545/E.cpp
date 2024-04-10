#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
map<pii, ll> back;
vector<ll> g[300001];
vector<ll> d[300001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
ll di[300001],wei[300001],im[300001];
ll so[300001];
vector<ll> ans;
bool vis[300001];
int main() {
	ll n, m,i,a,b,s,x,y,sc;
	ll c,pos;
	scanf("%lld%lld", &n, &m);
	for (i = 1; i <= m; i++)scanf("%lld%lld%lld", &a, &b, &c), g[a].push_back(b), g[b].push_back(a), d[a].push_back(c), d[b].push_back(c), back[make_pair(a, b)] = back[make_pair(b,a)]= i,wei[i]=c;
	scanf("%lld", &s);
	memset(di, 0x3f, sizeof(di));
	di[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		x = pq.top().second;
		sc = pq.top().first;
		pq.pop();
		if (di[x] < sc)continue;
		for (i = 0; i < g[x].size(); i++) {
			y = g[x][i];
			pos = d[x][i] + di[x];
			if (pos < di[y]||(pos==di[y]&&im[y]>d[x][i]))di[y] = pos, so[y] = x, pq.push(make_pair(pos, y)),im[y]=d[x][i];
		}
	}
	vis[s] = 1;
	ll temp;
	ll tot = 0;
	for (i = 1; i <= n; i++) {
		x = i;
		while (!vis[x]) { vis[x] = 1, ans.push_back(temp = back[make_pair(x, so[x])]), x = so[x], tot += wei[temp]; }
	}
	printf("%lld\n", tot);
	for (ll q : ans)printf("%lld ", q);
	getchar(); getchar();
}