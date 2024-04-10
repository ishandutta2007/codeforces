#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

typedef long long ll;

int n;
ll a, b, c, d;
map<pair<ll, ll>, int> mp;
vector<pair<int, int> > ans;
int cnt;

int id(ll a, ll b, ll c, ll d){
	a *= d, b *= c;
	pair<ll, ll> p = {a / __gcd(a, b), b / __gcd(a, b)};
	if(!mp[p]) mp[p] = ++cnt;
	return mp[p] + n;
}

vector<int> v[maxn];

bool vis[maxn];

int dfs(int i){
	vis[i] = true;
	int x = i <= n ? i : 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(vis[to]) continue;
		int y = dfs(to);
		if(!y) continue;
		if(!x) x = y;
		else ans.push_back({x, y}), x = 0;
	}
	return x;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		int x = id(a + b, b, c, d);
		v[x].push_back(i), v[i].push_back(x);
		x = id(a, b, c + d, d);
		v[x].push_back(i), v[i].push_back(x);
	} 
	for(int i = 1;i <= n + cnt;i++) if(!vis[i]) dfs(i);
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
}