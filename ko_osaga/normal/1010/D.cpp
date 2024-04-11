#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1000005;
const int MAXT = 2100000;

int n;
int typ[MAXN], in1[MAXN], in2[MAXN];
int dp[MAXN], sz[MAXN], din[MAXN], dout[MAXN];
int ans[MAXN];
int piv = 0;

struct seg{
	int lazy[MAXT]; // if no set, lazy flip
	int setv[MAXT]; // setting in range
	void flip_node(int x){
		if(setv[x] != -1){
			setv[x] ^= 1;
		}
		else{
			lazy[x] ^= 1;
		}
	}
	void lazydown(int v){
		if(setv[v] != -1){
			setv[2*v] = setv[v];
			setv[2*v+1] = setv[v];
			setv[v] = -1;
			lazy[v] = 0;
		}
		else if(lazy[v]){
			flip_node(2*v);
			flip_node(2*v+1);
			lazy[v] = 0;
		}
	}
	void init(){
		memset(setv, -1, sizeof(setv));
	}
	void set(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			setv[p] = v;
			return;
		}
		int pm = (ps+pe)/2;
		lazydown(p);
		set(s, e, ps, pm, 2*p, v);
		set(s, e, pm+1, pe, 2*p+1, v);
	}
	void flip(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			flip_node(p);
			return;
		}
		int pm = (ps+pe)/2;
		lazydown(p);
		flip(s, e, ps, pm, 2*p, v);
		flip(s, e, pm+1, pe, 2*p+1, v);
	}
	int query(int pos, int s, int e, int p){
		if(s == e) return setv[p];
		lazydown(p);
		int m = (s+e)/2;
		if(pos <= m) return query(pos, s, m, 2*p);
		else return query(pos, m+1, e, 2*p+1);
	}
}seg;

void flip(int v){
	seg.flip(din[v], dout[v] - 1, 0, piv - 1, 1, 1);
}

void make_one(int v){
	seg.set(din[v], dout[v] - 1, 0, piv - 1, 1, 1);
}

void make_zero(int v){
	seg.set(din[v], dout[v] - 1, 0, piv - 1, 1, 0);
}

void dfs(int x){
	din[x] = piv;
	sz[x] = 1;
	if(typ[x] == 5){
		ans[piv] = 1 - in1[x];
		piv++;
		dp[x] = in1[x];
	}
	else if(typ[x] == 4){
		dfs(in1[x]);
		sz[x] += sz[in1[x]];
		dp[x] = !dp[in1[x]];
	}
	else{
		dfs(in1[x]);
		dfs(in2[x]);
		if(typ[x] == 1) dp[x] = (dp[in1[x]] & dp[in2[x]]);
		if(typ[x] == 2) dp[x] = (dp[in1[x]] | dp[in2[x]]);
		if(typ[x] == 3) dp[x] = (dp[in1[x]] ^ dp[in2[x]]);
	}
	dout[x] = piv;
}

void solve(int x){
	if(typ[x] == 5){
		return;
	}
	if(typ[x] == 4){
		solve(in1[x]);
		flip(in1[x]);
	}
	else{
		solve(in1[x]);
		solve(in2[x]);
		if(typ[x] == 1){
			if(dp[in1[x]] == 0){
				make_zero(in2[x]);
			}
			if(dp[in2[x]] == 0){
				make_zero(in1[x]);
			}
		}
		if(typ[x] == 2){
			if(dp[in1[x]] == 1){
				make_one(in2[x]);
			}
			if(dp[in2[x]] == 1){
				make_one(in1[x]);
			}
		}
		if(typ[x] == 3){
			if(dp[in1[x]] == 1){
				flip(in2[x]);
			}
			if(dp[in2[x]] == 1){
				flip(in1[x]);
			}
		}
	}
}

int main(){
	int mp[256];
	mp['A'] = 1; // and
	mp['O'] = 2; // or
	mp['X'] = 3; // xor
	mp['N'] = 4; // not
	mp['I'] = 5; // in
	scanf("%d",&n);
	char buf[10];
	for(int i=1; i<=n; i++){
		scanf("%s %d",buf,&in1[i]);
		typ[i] = mp[*buf];
		if(mp[*buf] <= 3) scanf("%d",&in2[i]);
	}
	seg.init();
	dfs(1);
	for(int i=0; i<piv; i++) seg.set(i, i, 0, piv - 1, 1, ans[i]);
	solve(1);
	for(int i=1; i<=n; i++){
		if(typ[i] == 5){
			printf("%d", seg.query(din[i], 0, piv - 1, 1));
		}
	}
}