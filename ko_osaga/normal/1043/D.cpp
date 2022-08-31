#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
using pi = pair<int, int>;
using lint = long long;

struct disj{
	int pa[MAXN], sz[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
		fill(sz, sz + n + 1, 1);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; sz[p] += sz[q];
		return 1;
	}
}disj;

vector<pi> v;
int n, m, a[11][100005];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&a[i][j]);
		}
		for(int j=1; j<n; j++) v.emplace_back(a[i][j-1], a[i][j]);
	}
	disj.init(n);
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); ){
		int e = i;
		while(e < v.size() && v[e] == v[i]) e++;
		if(e - i == m){
			disj.uni(v[i].first, v[i].second);
		}
		i = e;
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		if(disj.find(i) == i){
			ret += 1ll * disj.sz[i] * (disj.sz[i] + 1) / 2;
		}
	}
	cout << ret << endl;
}