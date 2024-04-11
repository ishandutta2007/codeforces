#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;

struct Group{
	pi ratio;
	int studentNum, studentRef;
	bool operator<(const Group &g)const{
		lint r1 = ratio.first * g.ratio.second;
		lint r2 = g.ratio.first * ratio.second;
		if(r1 != r2) return r1 > r2; // Age big: first
		return studentNum < g.studentNum; // Same: teacher first
	}
};

struct node{
	lint sum, opt, pfx, sfx;
	node(){
		sum = opt = pfx = sfx = 0;
	}
	node(lint x){
		sum = x;
		opt = pfx = sfx = min(x, 0ll);
	}
	node operator+(const node &n)const{
		node ret;
		ret.sum = sum + n.sum;
		ret.pfx = min(pfx, sum + n.pfx);
		ret.sfx = min(n.sfx, n.sum + sfx);
		ret.opt = min({opt, n.opt, sfx + n.pfx});
		return ret;
	}
};

struct seg{
	vector<node> tree;
	int lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		tree.clear();
		tree.resize(2 * lim + 10, node(0));
	}
	void set(int x, int v){
		x += lim;
		tree[x] = node(v);
		while(x > 1){
			x >>= 1;
			tree[x] = tree[2*x] + tree[2*x+1];
		}
	}
	int query(){
		return tree[1].pfx;
	}
}seg;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q; cin >> q;
	while(q--){
		vector<Group> g;
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		vector<int> idxTotal(m);
		vector<vector<int>> idxStud(m);
		vector<vector<int>> grp(m);
		for(int i = 0; i < m; i++){
			int k; cin >> k;
			grp[i].resize(k);
			idxStud[i].resize(k);
			for(auto &j : grp[i]) cin >> j;
		}
		for(int i = 0; i < n; i++){
			g.push_back({pi(a[i], 1), -1, -1});
		}
		for(int i = 0; i < m; i++){
			lint sum = 0;
			for(int j = 0; j < sz(grp[i]); j++){
				sum += grp[i][j];
			}
			g.push_back({pi(sum, sz(grp[i])), i, -1});
			for(int j = 0; j < sz(grp[i]); j++){
				g.push_back({pi(sum - grp[i][j], sz(grp[i]) - 1), i, j});
			}
		}
		sort(all(g));
		seg.init(sz(g));
		for(int i = 0; i < sz(g); i++){
			if(g[i].studentNum == -1){
				seg.set(i, 1);
			}
			else{
				int j = g[i].studentNum;
				if(g[i].studentRef == -1){
					seg.set(i, -1);
					idxTotal[j] = i;
				}
				else{
					idxStud[j][g[i].studentRef] = i;
				}
			}
		}
		for(int i = 0; i < m; i++){
			seg.set(idxTotal[i], 0);
			for(auto &j : idxStud[i]){
				seg.set(j, -1);
				cout << (seg.query() < 0 ? "0" : "1");
				seg.set(j, 0);
			}
			seg.set(idxTotal[i], -1);
		}
		cout << "\n";
	}
}