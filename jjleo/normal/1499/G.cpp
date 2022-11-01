#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

const int p = 998244353;

int n1, n2, m, q;
int id[maxn];
int opt, x, y;
bool tag[maxn];
int pw[maxn], ans, cnt, tot;
int l[maxn], r[maxn];
deque<int> d[maxn];

void modify(int x){
	for(int i = 0;i < d[x].size();i += 2){
		int j = d[x][i];
		tag[j] ^= 1;
		if(tag[j]) ans = (ans + pw[j]) % p, tot++;
		else ans = (ans + p - pw[j]) % p, tot--;
	}
}

int merge(int x, int y){
	modify(x), modify(y);
	if(d[x].size() > d[y].size()) swap(x, y);
	if(r[x] == l[y]){
		for(int i = (int)d[x].size() - 1;~i;i--) d[y].push_front(d[x][i]);
		l[y] = l[x];
	}else if(l[x] == l[y]){
		for(int i = 0;i < d[x].size();i++) d[y].push_front(d[x][i]);
		l[y] = r[x];
	}else if(r[x] == r[y]){
		for(int i = (int)d[x].size() - 1;~i;i--) d[y].push_back(d[x][i]);
		r[y] = l[x];
	}else if(l[x] == r[y]){
		for(int i = 0;i < d[x].size();i++) d[y].push_back(d[x][i]);
		r[y] = r[x];
	}
	modify(y);
	return y;
}

void addEdge(int x, int y, int i){
	y += n1;
	int j = ++cnt;
	d[j].push_back(i);
	modify(j), l[j] = x, r[j] = y;
	if(!id[x] && !id[y]){
		id[x] = id[y] = j;
		return;
	}
	if(id[x] == id[y]){
		merge(j, id[x]);
		id[x] = id[y] = 0;
		return;
	}
	if(id[x]) j = merge(id[x], j), id[x] = 0;
	if(id[y]) j = merge(id[y], j), id[y] = 0;
	id[l[j]] = id[r[j]] = j;
}

int main(){
	pw[0] = 1;for(int i = 1;i < maxn;i++) pw[i] = (pw[i - 1] + pw[i - 1]) % p;
	scanf("%d%d%d", &n1, &n2, &m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &x, &y);
		addEdge(x, y, i);
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d", &x, &y);
			addEdge(x, y, ++m);
			printf("%d\n", ans);
		}else{
			printf("%d", tot);
			for(int i = 1;i <= m;i++) if(tag[i]) printf(" %d", i);
			puts("");
		}
		fflush(stdout);
	}
}