#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

const int p = 1e9 + 7;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

vector<int> v1[maxn], v2[maxn];
int eu[maxn << 1], tot1, pos[maxn], dep[maxn], dfn[maxn], tot2;
int st[maxn << 1][25], lg[maxn << 1];


void dfs1(int i, int fa){
	eu[pos[i] = ++tot1] = i, dfn[i] = ++tot2, dep[i] = dep[fa] + 1;
	for(int j = 0;j < v1[i].size();j++){
		int to = v1[i][j];
		if(to == fa) continue;
		dfs1(to, i);
		eu[++tot1] = i;
	}
}

void init(){
	for(int i = 2;i <= tot1;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
	for(int i = 1;i <= tot1;i++) st[i][0] = eu[i];
	for(int j = 1;j <= 20;j++){
		for(int i = 1;i + (1 << j) - 1 <= tot1;i++){
			st[i][j] = pos[st[i][j - 1]] < pos[st[i + (1 << (j - 1))][j - 1]] ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1]; 
		}
	}
}

int lca(int x, int y){
	if(pos[x] > pos[y]) swap(x, y);
	return pos[st[pos[x]][lg[pos[y] - pos[x]]]] < pos[st[pos[y] - (1 << lg[pos[y] - pos[x]]) + 1][lg[pos[y] - pos[x]]]] ? st[pos[x]][lg[pos[y] - pos[x]]] : st[pos[y] - (1 << lg[pos[y] - pos[x]]) + 1][lg[pos[y] - pos[x]]];
}

inline bool cmp(int x, int y){
	return dfn[x] < dfn[y];
}

int sk[maxn], top;

void insert(int x){
	if(!top){
		sk[++top] = x;
		return;
	}
	int y = sk[top], z = lca(x, y);
	if(z == y){//  
		sk[++top] = x;
		return;
	}
	//
	while(dfn[sk[top]] > dfn[z]){// LCALCA 
		y = sk[top--];
		if(!top || dfn[sk[top]] <= dfn[z]) break;
		v2[sk[top]].push_back(y);
		
	}
	if(!top || sk[top] != z){//lca 
		sk[++top] = z;// 
	}
	v2[z].push_back(y);
	sk[++top] = x;
}

int val;
vector<int> v;
int siz[maxn], sum;

void dfs2(int i, int fa){
	for(int j = 0;j < v2[i].size();j++) dfs2(v2[i][j], i);
	if(fa){
		val = (val + 1ll * (dep[i] - dep[fa]) * siz[i] % p * (sum + p - siz[i])) % p;
		siz[fa] = (siz[fa] + siz[i]) % p;
	}
	siz[i] = 0, v2[i].clear();
	
}

int n;
int x, y;
int a[maxn];
int prm[maxn], cnt, phi[maxn], mu[maxn];
int f[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &x), a[x] = i;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v1[x].push_back(y), v1[y].push_back(x);
	}
	phi[1] = mu[1] = 1;
	for(int i = 2;i <= n;i++){
		if(!phi[i]){
			prm[++cnt] = i;
			phi[i] = i - 1;
			mu[i] = p - 1;
		}
		for(int j = 1;j <= cnt && prm[j] * i <= n;j++){
			if(i % prm[j] == 0){
				phi[i * prm[j]] = phi[i] * prm[j];
				mu[i * prm[j]] = 0;
				break;
			}
			phi[i * prm[j]] = phi[i] * (prm[j] - 1);
			mu[i * prm[j]] = p - mu[i];
		}
	}
	for(int i = 1;i <= n;i++){
		int inv = fpow(phi[i], p - 2);
		for(int j = 1;i * j <= n;j++){
			f[i * j] = (f[i * j] + 1ll * i * inv % p * mu[j]) % p;
		}
	}
	dfs1(1, 0), init();
	int ans = 0;
	for(int t = 1;t <= n;t++){
		v.clear(), val = sum = 0;
		for(int i = 1;i * t <= n;i++){
			v.push_back(a[i * t]);
			sum = (sum + (siz[a[i * t]] = phi[i * t])) % p;
		}
		sort(v.begin(), v.end(), cmp);
		sk[++top] = 1;
		for(int i = 0;i < v.size();i++) if(v[i] ^ 1) insert(v[i]);
		while(top) if(--top) v2[sk[top]].push_back(sk[top + 1]);
		dfs2(1, 0);
		ans = (ans + 2ll * val * f[t]) % p;
	}
	printf("%d", 1ll * ans * fpow(1ll * n * (n - 1) % p, p - 2) % p);
}