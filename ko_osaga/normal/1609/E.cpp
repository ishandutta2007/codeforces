#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXT = 270000;

struct mtrx{
	int adj[6][6];
	mtrx(){
		memset(adj, 0x3f, sizeof(adj));
		for(int i = 0; i < 6; i++) adj[i][i] = 0;
	}
	mtrx(char c){
		memset(adj, 0x3f, sizeof(adj));
		int cost[6];
		cost[0] = (c == 'a' || c == 'b');
		cost[1] = (c == 'a');
		cost[2] = (c == 'a' || c == 'c');
		cost[3] = (c == 'b');
		cost[4] = (c == 'c');
		cost[5] = (c == 'b' || c == 'c');
		for(int i = 0; i < 6; i++){
			for(int j = i; j < 6; j++){
				if(i == 2 && j == 3) continue;
				adj[i][j] = cost[i];
			}
		}
	}
	mtrx operator*(const mtrx &m)const{
		mtrx ret;
		memset(ret.adj, 0x3f, sizeof(ret.adj));
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 6; j++){
				for(int k = 0; k < 6; k++){
					ret.adj[j][k] = min(ret.adj[j][k], adj[j][i] + m.adj[i][k]);
				}
			}
		}
		return ret;
	}
};

struct seg{
	mtrx tree[MAXT];
	int lim;
	void init(string &s){
		for(lim = 1; lim <= sz(s); lim <<= 1);
		fill(tree, tree + MAXT, mtrx());
		for(int i = 0; i < sz(s); i++){
			tree[i + lim] = mtrx(s[i]);
		}
		for(int i = lim-1; i; i--) tree[i] = tree[2*i] * tree[2*i+1];
	}
	void upd(int x, char c){
		x += lim;
		tree[x] = mtrx(c);
		while(x > 1){
			x >>= 1;
			tree[x] = tree[2*x] * tree[2*x+1];
		}
	}
}seg;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q; cin >> n  >> q;
	string s; cin >> s;
	seg.init(s);
	while(q--){
		int x; string c;
		cin >> x >> c;
		x--;
		s[x] = c[0];
		seg.upd(x, c[0]);
		int ret = 1e9;
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 6; j++){
				ret = min(ret, seg.tree[1].adj[i][j]);
			}
		}
		cout << ret << '\n';
	}
}