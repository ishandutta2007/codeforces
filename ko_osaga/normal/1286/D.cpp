#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;
const int MAXT = 270005;
const int mod = 998244353;

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	for(int i=p; i; i>>=1){
		if(i & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
	}
	return ret;
}

struct matrix{
	int adj[2][2];
	matrix(){
		adj[0][0] = 1;
		adj[0][1] = 0;
		adj[1][0] = 0;
		adj[1][1] = 1;
	}
	matrix operator*(const matrix &m)const{
		matrix ret;
		memset(ret.adj, 0, sizeof(ret.adj));
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				for(int k=0; k<2; k++){
					ret.adj[j][k] += 1ll * adj[j][i] * m.adj[i][k] % mod;
					if(ret.adj[j][k] >= mod) ret.adj[j][k] -= mod;
				}
			}
		}
		return ret;
	}
}mtrx[MAXN];

struct seg{
	matrix tree[MAXT];
	int lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		for(int i=0; i<n; i++) tree[i + lim] = mtrx[i];
		for(int i=lim-1; i; i--) tree[i] = tree[2*i] * tree[2*i+1];
	}
	void upd(int x){
		tree[x + lim] = mtrx[x];
		x += lim;
		for(int i=x/2; i>=1; i>>=1){
			tree[i] = tree[2*i] * tree[2*i+1];
		}
	}
	lint query(){
		lint ret = 0;
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				ret += tree[1].adj[i][j];
			}
		}
		return ret % mod;
	}
}seg;

struct ev{
	pi p;
	int x1, m1, x2, m2;
	bool operator<(const ev &e)const{
		return 1ll * p.first * e.p.second < 1ll * e.p.first * p.second;
	}
};

int n, x[MAXN], v[MAXN], p[MAXN];
vector<ev> event;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d %d",&x[i],&v[i],&p[i]);
	}
	lint INV100 = ipow(100, mod - 2);
	mtrx[0].adj[0][0] = (100 - p[0]) * INV100 % mod;
	mtrx[0].adj[0][1] = 0;
	mtrx[0].adj[1][0] = 0;
	mtrx[0].adj[1][1] = p[0] * INV100 % mod;
	for(int i=1; i<n; i++){
		pi frac1 = pi(x[i] - x[i-1], v[i] + v[i-1]);
		event.push_back({frac1, i-1, 1, i, 0});
		if(v[i-1] < v[i]){
			frac1 = pi(x[i] - x[i-1], v[i] - v[i-1]);
			event.push_back({frac1, i-1, 0, i, 0});
		}
		if(v[i-1] > v[i]){
			frac1 = pi(x[i] - x[i-1], v[i-1] - v[i]);
			event.push_back({frac1, i-1, 1, i, 1});
		}
		mtrx[i].adj[0][0] = (100 - p[i]) * INV100 % mod;
		mtrx[i].adj[0][1] = p[i] * INV100 % mod;
		mtrx[i].adj[1][0] = (100 - p[i]) * INV100 % mod;
		mtrx[i].adj[1][1] = p[i] * INV100 % mod;
	}
	sort(all(event));
	seg.init(n);
	lint ret = 0;
	for(int i=0; i<sz(event); i++){
		lint cur_ans = 1ll * event[i].p.first * ipow(event[i].p.second, mod - 2) % mod;
		lint cur_prob = seg.query();
		mtrx[event[i].x2].adj[event[i].m1][event[i].m2] = 0;
		seg.upd(event[i].x2);
		lint nxt_prob = seg.query();
		ret += cur_ans * (cur_prob - nxt_prob + mod) % mod;
		ret %= mod;
	}
	cout << ret << endl;
}