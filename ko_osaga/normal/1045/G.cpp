#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
using lint = long long;
const int MAXN = 100005;
const int mod = 1e9 + 7;

struct line{
	int x, r, k;
	bool operator<(const line &l)const{
		return r < l.r;
	}
}a[MAXN];

vector<int> x, k;
vector<int> elem[MAXN], bit[MAXN];

int query(vector<int> &v, vector<int> &w, int x){
	x = upper_bound(w.begin(), w.end(), x) - w.begin() - 1;
	int ret = 0;
	while(x){
		ret += v[x];
		x -= x & -x;
	}
	return ret;
}

void add(vector<int> &v, vector<int> &w, int x){
	x = lower_bound(w.begin(), w.end(), x) - w.begin();
	while(x < v.size()){
		v[x]++;
		x += x & -x;
	}
}

int n, K;
int ks[MAXN], ke[MAXN];
int xs[MAXN], xe[MAXN];

int main(){
	scanf("%d %d",&n,&K);
	for(int i=0; i<n; i++){
		scanf("%d %d %d",&a[i].x,&a[i].r,&a[i].k);
		x.push_back(a[i].x);
		k.push_back(a[i].k);
	}
	sort(a, a + n);
	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	sort(k.begin(), k.end());
	k.resize(unique(k.begin(), k.end()) - k.begin());
	for(int i=0; i<n; i++){
		xs[i] = lower_bound(x.begin(), x.end(), a[i].x - a[i].r) - x.begin();
		xe[i] = lower_bound(x.begin(), x.end(), a[i].x + a[i].r + 1) - x.begin() - 1;
		ks[i] = lower_bound(k.begin(), k.end(), a[i].k - K) - k.begin();
		ke[i] = lower_bound(k.begin(), k.end(), a[i].k + K + 1) - k.begin() - 1;
		a[i].x = lower_bound(x.begin(), x.end(), a[i].x) - x.begin();
		a[i].k = lower_bound(k.begin(), k.end(), a[i].k) - k.begin();
		elem[a[i].k].push_back(a[i].x + 1);
	}
	for(int i=0; i<k.size(); i++){
		elem[i].push_back(-1);
		sort(elem[i].begin(), elem[i].end());
		elem[i].resize(unique(elem[i].begin(), elem[i].end()) - elem[i].begin());
		bit[i].resize(elem[i].size());
	}
	lint ans = 0;
	for(int i=n-1; i>=0; i--){
	//	printf("val = %d %d\n", a[i].k, a[i].x + 1);
	//	printf("%d %d %d %d\n", ks[i], ke[i], xs[i] + 1, xe[i] + 1);
		for(int j=ks[i]; j<=ke[i]; j++){
			ans += query(bit[j], elem[j], xe[i] + 1) - query(bit[j], elem[j], xs[i]);
		}
		add(bit[a[i].k], elem[a[i].k], a[i].x + 1);
	}
	cout << ans << endl;
}

/*
vector<int> gph[MAXN];
vector<int> bcc[MAXN], cmp[MAXN];
int dfn[MAXN], low[MAXN], piv;

void dfs(int x, int p){
	dfn[x] = low[x] = ++piv;
	for(auto &i : gph[x]){
		if(i == p) continue;
		if(!dfn[i]){
			dfs(i, x);
			low[x] = min(low[x], low[i]);
		}
		else low[x] = min(low[x], dfn[i]);
	}
}

void color(int x, int p){
	if(p){
		bcc[p].push_back(x);
		cmp[x].push_back(p);
	}
	for(auto &i : gph[x]){
		if(cmp[i].size()) continue;
		if(low[i] >= dfn[x]){
			bcc[++c].push_back(x);
			cmp[x].push_back(c);
			color(i, c);
		}
		else color(i, p);
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0; i<m; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	color(1, 0);
	for(int i=1; i<=n; i++){
		for(int j=1; j<cmp[i].size(); j++){
			par[cmp[i][j]] = cmp[i][0];
			dep[cmp[i][j]] = cmp[i][0];
		}
	}
	while(q--){
		int s, e; scanf("%d %d",&s,&e);
*/