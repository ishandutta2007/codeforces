#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, k;
int x, y;
vector<int> v[maxn];
int d[maxn];
queue<int> q;
bool del[maxn];
int siz[maxn];
int sum, mn, id;
int ans[maxn];

void dfs1(int i, int fa){
	siz[i] = 1;
	int val = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa || del[to]) continue;
		dfs1(to, i);
		val = max(val, siz[to]);
		siz[i] += siz[to];
	}
	val = max(val, sum - siz[i]);
	if(mn > val) mn = val, id = i;
} 

int f[maxn];
vector<int> w;
int dep[maxn];

void dfs2(int i, int fa){
	dep[i] = dep[fa] + 1;
	w.push_back(i);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa || del[to]) continue;
		dfs2(to, i); 
	}
} 

void dfs3(int i){
	dfs1(i, 0);
	int rt = id;
	dep[rt] = 0, w.clear(), w.push_back(rt);
	for(int j = 0;j < v[rt].size();j++){
		int to = v[rt][j];
		if(del[to]) continue;
		dfs2(to, rt);
	}
	for(int j = 0;j <= sum;j++) f[j] = 0;
	for(int j = 0;j < w.size();j++){
		int x = w[j];
		if(d[x] < dep[x]) continue;
		f[min(d[x] - dep[x], sum)] = max(f[min(d[x] - dep[x], sum)], d[x]);
	}
	for(int j = sum - 1;~j;j--) f[j] = max(f[j], f[j + 1]);
	for(int j = 0;j < w.size();j++) ans[w[j]] = max(ans[w[j]], f[dep[w[j]] + 1]);
	del[rt] = true;
	int s = sum;
	for(int j = 0;j < v[rt].size();j++){
		int to = v[rt][j];
		if(del[to]) continue;
		if(siz[to] > siz[rt]) sum = mn = s - siz[rt];
		else sum = mn = siz[to];
		dfs3(to);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	scanf("%d", &k);
	memset(d, 0x3f, sizeof(d));
	while(k--){
		scanf("%d", &x);
		d[x] = 0, q.push(x);
	}
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int i = 0;i < v[x].size();i++){
			int to = v[x][i];
			if(d[to] > d[x] + 1) d[to] = d[x] + 1, q.push(to);
		}
	}
	sum = mn = n;
	dfs3(1);
	for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
}