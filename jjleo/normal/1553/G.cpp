#include <bits/stdc++.h>
#define maxn 150086
#define maxm 1000086

using namespace std;

int n, q;
int p[maxm], cnt;
bool tag[maxm];
int f[maxm];
vector<int> v[maxm];

int fa[maxm << 1], siz[maxm << 1];
set<pair<int, int> > st;
int a[maxn], x, y;
bool vis[maxm << 1];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]); 
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x];
}

int main(){
	for(int i = 2;i < maxm;i++){
		if(!tag[i]) p[++cnt] = i, f[i] = i;
		for(int j = 1;j <= cnt && p[j] * i < maxm;j++){
			tag[p[j] * i] = true;
			f[p[j] * i] = p[j];
			if(i % p[j] == 0) break;
		}
	}
	for(int i = 2;i < maxm;i++){
		int x = i;
		while(x ^ 1){
			if(v[i].empty() || f[x] != v[i].back()) v[i].push_back(f[x]);
			x /= f[x];
		}
	}
	for(int i = 1;i < (maxm << 1);i++) fa[i] = i, siz[i] = 1;
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		for(int j = 0;j < v[a[i]].size();j++) merge(a[i], maxm + v[a[i]][j]);
	}
	for(int i = 1;i <= n;i++){
		vector<int> w;
		w.push_back(find(a[i])), vis[find(a[i])] = true;
		for(int j = 0;j < v[a[i] + 1].size();j++){
			int x = find(v[a[i] + 1][j] + maxm);
			if(vis[x]) continue;
			vis[x] = true, w.push_back(x);
		}
		for(int j = 0;j < w.size();j++){
			vis[w[j]] = false;
			for(int k = 0;k < j;k++){
				st.insert({min(w[j], w[k]), max(w[j], w[k])});
			}
		}
	}
	while(q--){
		scanf("%d%d", &x, &y);
		x = find(a[x]), y = find(a[y]);
		if(x == y) puts("0");
		else if(st.find({min(x, y), max(x, y)}) != st.end()) puts("1");
		else puts("2");
	}
}