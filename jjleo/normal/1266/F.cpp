#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n;
map<int, int> mp[maxn];
int x, y;
vector<int> v[maxn];
int mx[maxn], sx[maxn], id[maxn];

void dfs1(int i, int fa){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs1(to, i);
		if(mx[to] + 1 > mx[i]) sx[i] = mx[i], mx[i] = mx[to] + 1, id[i] = to;
		else sx[i] = max(sx[i], mx[to] + 1);
	}
}

void dfs2(int i, int fa){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		mp[i][(id[to] == i ? sx[to] : mx[to]) + 1]++;
		//printf("%d %d %d--\n", i, to, (id[to] == i ? sx[to] : mx[to]) + 1);
	}
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		int val = id[i] == to ? sx[i] : mx[i];
		if(val + 1 > mx[to]) sx[to] = mx[to], mx[to] = val + 1, id[to] = i;
		else sx[to] = max(sx[to], val + 1);
		dfs2(to, i);
	}
}

int ans[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++) scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
	for(int i = 1;i <= n;i++) ans[1] = max(ans[1], (int)v[i].size() + 1);
	dfs1(1, 0), dfs2(1, 0);
	for(int i = 1;i <= n;i++){
		int sum = 0;
		for(map<int, int>::reverse_iterator it = mp[i].rbegin();it != mp[i].rend();++it){
			ans[it->first * 2 + 1] = max(ans[it->first * 2 + 1], sum + 1);
			sum += it->second;
			ans[it->first * 2] = max(ans[it->first * 2], sum);
			ans[it->first * 2 - 1] = max(ans[it->first * 2 - 1], sum);
		}
	}
	for(int i = 1;i <= n;i++) for(auto j : v[i]) if(i < j){
		vector<pair<int, int> > a, b, c;
		for(auto x : mp[i]) a.push_back(x);
		for(auto x : mp[j]) b.push_back(x);
		c.resize(a.size() + b.size());
		merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
		//printf("%d %d: ", i, j);for(auto x : c) printf("[%d %d] ", x.first, x.second);puts("");
		int sum = 0;
		for(int i = c.size() - 1;~i;i--){
			sum += c[i].second;
			ans[c[i].first * 2] = max(ans[c[i].first * 2], sum - 2);
		}
	}
	for(int i = n - 2;i;i--) ans[i] = max(ans[i], ans[i + 2]);
	for(int i = 1;i <= n;i++) printf("%d ", max(ans[i], 1));
}