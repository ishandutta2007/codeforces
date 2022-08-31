#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 1005;

struct disj{
	int sz[MAXN], pa[MAXN];
	void init(int n){
		fill(sz, sz + n + 1, 1);
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p;
		sz[p] += sz[q];
		return 1;
	}
}disj;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q; cin >> n  >> q;
	disj.init(n);
	int ans = 1;
	int comp = 0;
	for(int i = 1; i <= q; i++){
		int x, y; cin >> x >> y;
		if(!disj.uni(x, y)) comp++;
		vector<pi> w;
		for(int i = 1; i <= n; i++){
			if(disj.find(i) != i) continue;
			w.emplace_back(disj.sz[i], i);
		}
		sort(all(w));
		reverse(all(w));
		int ans = 0;
		for(int i = 0; i < comp + 1; i++){
			ans += w[i].first;
		}
		cout << ans - 1 << '\n';
	}
}