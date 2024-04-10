#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n;
ll k;
int x, y;
vector<int> v[maxn];
int cur[maxn];
int fa[maxn], siz[maxn], mn, id;
ll sum, par;

void dfs1(int i, int fa){
	siz[i] = 1;
	int val = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs1(to, i);
		val = max(val, siz[to]), siz[i] += siz[to]; 
	}
	val = max(val, n - siz[i]);
	if(val < mn) mn = val, id = i;
}

void dfs2(int i){
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i]) continue;
		fa[to] = i, dfs2(to);
		siz[i] += siz[to];
	}
	if(siz[i] ^ n) sum += siz[i], par += siz[i] & 1;
}

priority_queue<pair<int, int> > q;
set<pair<int, int> > st[maxn];
int dep[maxn], cnt[maxn];

void dfs3(int i, int x){
	dep[i] = dep[fa[i]] + 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i]) continue;
		cnt[i]++, dfs3(to, x);
	}
	if(cnt[i]) st[x].insert({dep[i], i});
}

bool vis[maxn];
vector<int> a;

void dfs4(int i){
	if(!vis[i]) a.push_back(i);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i]) continue;
		dfs4(to);
	}
}

int main(){
	scanf("%d%lld", &n, &k), mn = n;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(id);
	if(k < par || k > sum || ((k - sum) & 1)) return printf("NO"), 0;
	for(int i = 0;i < v[id].size();i++){
		int to = v[id][i];
		if(siz[to] == 1) continue;
		q.push({siz[to], to});
		dfs3(to, to);
	}
	puts("YES");
	ll d = sum - k;
	while(d){
		int x = q.top().second;q.pop();
		int y = st[x].rbegin()->second;
		if(d < 2 * dep[y]){
			d >>= 1;
			y = st[x].lower_bound({(int)d, 0})->second;
			vector<int> a; 
			for(int &i = cur[y];i < v[y].size() && a.size() < 2;i++){
				int to = v[y][i];
				if(to == fa[y] || vis[to]) continue;
				a.push_back(to);
			}
			if(a.size() < 2) a.push_back(y);
			printf("%d %d\n", a[0], a[1]), vis[a[0]] = vis[a[1]] = true;
			break;
		}else{
			d -= 2 * dep[y];
			vector<int> a; 
			for(int &i = cur[y];i < v[y].size() && a.size() < 2;i++){
				int to = v[y][i];
				if(to == fa[y] || vis[to]) continue;
				a.push_back(to);
			}
			if(a.size() < 2) a.push_back(y);
			printf("%d %d\n", a[0], a[1]), vis[a[0]] = vis[a[1]] = true;
			if(fa[a[0]] != id && !--cnt[fa[a[0]]]) st[x].erase({dep[fa[a[0]]], fa[a[0]]});
			if(fa[a[1]] != id && !--cnt[fa[a[1]]]) st[x].erase({dep[fa[a[1]]], fa[a[1]]});
		}
		if(siz[x] -= 2) q.push({siz[x], x});//debug:  
	}
	dfs4(id);
	for(int i = 0;i + a.size() / 2 < a.size();i++){
		printf("%d %d\n", a[i], a[i + a.size() / 2]);
	}
}