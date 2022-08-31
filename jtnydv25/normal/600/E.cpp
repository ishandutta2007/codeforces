#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;

map<int, int> freq[N];
int pos[N], mx[N], tree[N], cnt, color[N];
long long ans[N], sm[N];
vector<int> con[N];

inline void add(int i, int x, int y){
	int k = freq[i][x];
	freq[i][x] += y;
	if(k + y > mx[i]){
		mx[i] = k + y;
		sm[i] = x;
		return;
	}
	if(k + y == mx[i]){
		sm[i] += x;
	}
}
void dfs(int s, int p){
	int bigc = 0;
	tree[s] = 1;
	for(int v : con[s]){
		if(v != p){
			dfs(v, s);
			if(tree[v] > tree[bigc])
				bigc = v;
			tree[s] += tree[v];
		}
	}
	if(tree[s] == 1){
		++cnt;
		pos[s] = cnt;
		add(cnt, color[s], 1);
		ans[s] = color[s];
		return;
	}
	pos[s] = pos[bigc];
	add(pos[s], color[s], 1);
	for(int v : con[s]){
		if(v != p && v != bigc){
			for(auto it : freq[pos[v]]){
				add(pos[s], it.first, it.second);
			}
		}
	}
	ans[s] = sm[pos[s]];
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &color[i]);
	}
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++)
		printf("%lld ", ans[i]);
}