#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int c[maxn];
vector<int> v[maxn];
int x, y;
int siz[maxn], son[maxn];
int cnt[maxn], mx;
long long tot, ans[maxn];

void dfs1(int i, int fa){
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs1(to, i);
		siz[i] += siz[to];
		if(siz[to] > siz[son[i]]) son[i] = to;
	}
}

void cal(int i, int fa){
	cnt[c[i]]++;
	if(cnt[c[i]] == mx) tot += c[i];
	else if(cnt[c[i]] > mx) mx = cnt[c[i]], tot = c[i];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		cal(to, i);
	}
}

void del(int i, int fa){
	cnt[c[i]]--;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		del(to, i);
	}
}

void dfs2(int i, int fa, bool kp){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa || to == son[i]) continue;
		dfs2(to, i, false);
	}
	if(son[i]) dfs2(son[i], i, true);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa || to == son[i]) continue;
		cal(to, i);
	}
	cnt[c[i]]++;
	if(cnt[c[i]] == mx) tot += c[i];
	else if(cnt[c[i]] > mx) mx = cnt[c[i]], tot = c[i];
	ans[i] = tot;
	if(!kp) del(i, fa), mx = tot = 0;
}


int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &c[i]);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs1(1, 0), dfs2(1, 0, true);
	for(int i = 1;i <= n;i++) printf("%lld ", ans[i]);
}