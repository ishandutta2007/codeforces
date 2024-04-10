#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define F first
#define S second
#define pb push_back
#define sd(x) scanf("%d", &(x))

const int N = 5e5 + 10, logN = 21;

vi con[N];
int depth[N], par[N], st[N], en[N], t, val[N];
long long ans[N];

vector<int> nodes[N];

#define LSOne(S) (S & (-S))

ll B1[N], B2[N];

ll query(ll* ft, int b) {
    ll sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}

ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}

ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}

void update(ll* ft, int k, ll v) {
    for (; k < N; k += LSOne(k)) ft[k] += v;
}

void range_update(int i, int j, ll v)   {
    update(B1, i, v);
    update(B1, j + 1, -v);
    update(B2, i, v * (i - 1));
    update(B2, j + 1, -v * j);
}

void dfs(int s, int p, int d){
	depth[s] = d;
	nodes[d].pb(s);
	st[s] = ++t;
	for(int v : con[s]){
		if(v != p)
			dfs(v, s, d + 1);
	}
	en[s] = t;
}

int sz[N], rin[N], in[N], out[N], nxt[N], T = 0;

void dfs_sz(int v){
    sz[v] = 1;
    for(auto &u: con[v]){
        dfs_sz(u);
        sz[v] += sz[u];
        if(sz[u] > sz[con[v][0]])
            swap(u, con[v][0]);
    }
}

void dfs_hld(int v){
    in[v] = ++T;
    rin[in[v]] = v;
    for(auto u: con[v])
    {
        nxt[u] = (u == con[v][0] ? nxt[v] : u);
        dfs_hld(u);
    }
    out[v] = T;
}

int n, ceo;

void update(int node){
	while(node){
		range_update(in[nxt[node]], in[node], 1);
		node = par[nxt[node]];
	}
}

ll get(int node){
	ll ret = 0;
	while(node){
		ret += range_query(in[nxt[node]], in[node]);
		node = par[nxt[node]];
	}
	return ret;
}
int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(par[i]);
		if(par[i] == 0){
			ceo = i;
		}
		else{
			// con[i].pb(par[i]);
			con[par[i]].pb(i);
		}
	}
	dfs(ceo, 0, 1);

	dfs_sz(ceo);

	nxt[ceo] = ceo;

	dfs_hld(ceo);
	
	for(int d = 1; d <= n; d++){
		for(int v : nodes[d]){
			update(v);
		}		

		for(int v : nodes[d]){
			ans[v] = get(v) - d;
		}
	}

	for(int i = 1; i <= n;i++){
		printf("%lld ", ans[i]);
	}
}