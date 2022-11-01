#include <bits/stdc++.h>
#define maxn 50086

using namespace std;

typedef long long LL;

int n, m;
char s[10];
LL x[maxn], y[maxn];
vector<int> a[maxn];

struct Node{
	int son[2];
	bool tag;
}t[maxn * 100];

vector<int> v[maxn * 100];

int cnt = 1;
#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

void modify(int x, LL l, LL r, LL ll, LL rr, int d){
	if(ll <= l && r <= rr){
		a[d].push_back(x), t[x].tag = true;
		return;
	}
	LL mid = l + r >> 1;
	if(mid >= ll) modify(ls(x) ? ls(x) : ls(x) = ++cnt, l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x) ? rs(x) : rs(x) = ++cnt, mid + 1, r, ll, rr, d);
}

void merge(int x, int y){
	if(!ls(x) && !rs(x) && !ls(y) && !rs(y)){
		v[x].push_back(y), v[y].push_back(x);
		return;
	}
	merge(ls(x) ? ls(x) : x, ls(y) ? ls(y) : y), merge(rs(x) ? rs(x) : x, rs(y) ? rs(y) : y);
}

void merge(int x, LL l, LL r){
	if(!ls(x) && !rs(x)) return;
	LL mid = l + r >> 1;
	merge(ls(x), l, mid), merge(rs(x), mid + 1, r);
	merge(ls(x) ? ls(x) : ls(x) = ++cnt, rs(x) ? rs(x) : rs(x) = ++cnt);
}

int query(int x, LL l, LL r, LL pos){
	if(l == r) return x;
	LL mid = l + r >> 1;
	if(mid >= pos) return ls(x) ? query(ls(x), l, mid, pos) : x;
	return rs(x) ? query(rs(x), mid + 1, r, pos) : x;
}

int fa[maxn * 100];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
} 
bool ans[maxn];

int main(){
	scanf("%d%d", &n, &m);
	const LL N = (1ll << n) - 1;
	for(int i = 1;i <= m;i++){
		scanf("%s%lld%lld", s, &x[i], &y[i]);
		if(s[0] == 'b') modify(1, 0, N, x[i], y[i], i);
	}
	merge(1, 0, N);
	for(int i = 1;i <= cnt;i++) fa[i] = i;
	for(int i = 1;i <= cnt;i++) if(!t[i].tag){
		for(int j = 0;j < v[i].size();j++){
			int to = v[i][j];
			if(t[to].tag) continue;
			fa[find(i)] = find(to);
			//printf("%d %d--\n", i, to); 
		}
	}
	//for(int i = 1;i <= cnt;i++) printf("%d:%d %d--\n", i, ls(i), rs(i));
	for(int i = m;i;i--){
		if(a[i].empty()) ans[i] = find(query(1, 0, N, x[i])) == find(query(1, 0, N, y[i]));
		for(int j = 0;j < a[i].size();j++){
			int x = a[i][j];
			t[x].tag = false;
			for(int k = 0;k < v[x].size();k++){
				int to = v[x][k];
				if(t[to].tag) continue;
				fa[find(x)] = find(to);
			}
		}
	}
	for(int i = 1;i <= m;i++) if(a[i].empty()) printf("%d\n", ans[i]);
}