#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

struct Node{
	int edge[26];
	int fail;
}trie[maxn];

int cnt;
queue<int> q;

void build(){
	for(int i = 0;i < 26;i++){
		if(trie[0].edge[i]){
			q.push(trie[0].edge[i]);
		}
	} 
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0;i < 26;i++){
			if(trie[u].edge[i]){
				int v = trie[u].edge[i];
				trie[v].fail = trie[trie[u].fail].edge[i];
				q.push(trie[u].edge[i]);
			}else{
				trie[u].edge[i] = trie[trie[u].fail].edge[i];
			}
		}
	}
}

int n, m;
char s[maxn];
int id[maxn], tag[maxn];
int opt, x, y;
vector<int> v[maxn];

int dep[maxn], fa[maxn], siz[maxn], son[maxn];
int dfn[maxn], rnk[maxn], top[maxn];
int tot = -1;

void dfs1(int i){
	siz[i] = 1, dep[i] = dep[fa[i]] + 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i]) continue;
		fa[to] = i, dfs1(to);
		siz[i] += siz[to];
		if(!son[i] || siz[to] > siz[son[i]]) son[i] = to;//debug0    
	}
}

void dfs2(int i, int t){
	top[i] = t, dfn[i] = ++tot, rnk[dfn[i]] = i;
	if(!son[i]) return;
	dfs2(son[i], t);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i] || to == son[i]) continue;
		dfs2(to, to);
	}
}

int sum[maxn << 2];
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	sum[x] = max(sum[ls(x)], sum[rs(x)]);
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		sum[x] = d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}

int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return sum[x];
	int mid = l + r >> 1, ans = -1;
	if(mid >= ll) ans = max(ans, query(ls(x), l, mid, ll, rr));
	if(mid < rr) ans = max(ans, query(rs(x), mid + 1, r, ll, rr));
	return ans;
}

void build(int x, int l, int r){
	if(l == r){
		if(tag[rnk[l]]) sum[x] = 0;
		else sum[x] = -1;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}


int Query(int x, int y){
	int ans = -1;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = max(ans, query(1, 0, cnt, dfn[top[x]], dfn[x]));
		x = fa[top[x]];
	}
	if(dfn[x] > dfn[y]) swap(x, y);
	ans = max(ans, query(1, 0, cnt, dfn[x], dfn[y]));
	return ans;
}

multiset<int> st[maxn]; 
int a[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%s", s + 1);
		int len = strlen(s + 1), now = 0;
		for(int j = 1;j <= len;j++){
			if(!trie[now].edge[s[j] - 'a']) trie[now].edge[s[j] - 'a'] = ++cnt;
			now = trie[now].edge[s[j] - 'a'];
		}
		id[i] = now, tag[now] = true;
		st[now].insert(0);
		//printf("%d--\n", now);
	}
	build();
	for(int i = 1;i <= cnt;i++) v[trie[i].fail].push_back(i);
	dfs1(0), dfs2(0, 0);
	//for(int i = 0;i <= cnt;i++) printf("%d %d--\n", i, dfn[i]);
	build(1, 0, cnt);
	while(m--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d", &x, &y);
			st[id[x]].erase(st[id[x]].find(a[x])), st[id[x]].insert(a[x] = y);
			modify(1, 0, cnt, dfn[id[x]], *st[id[x]].rbegin());
		}else{
			scanf("%s", s + 1);
			int len = strlen(s + 1), now = 0, ans = -1;
			for(int i = 1;i <= len;i++){
				now = trie[now].edge[s[i] - 'a'];
				ans = max(ans, Query(0, now));
				//printf("%d %d--\n", now, query(1, 0, cnt, dfn[19], dfn[19]));
			}
			printf("%d\n", ans);
		}
	}
}