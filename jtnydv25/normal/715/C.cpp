#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

#define vi vector<int>
#define pb push_back
#define sd(x) scanf("%d", &(x))
#define ll long long
#define pd(n) printf("%d\n", n)

const int N = 1e5 + 10, logN = 18;

int tree[N], vis[N], parcen[N], pow10[N], mod, h1[N], h2[N], depth[N], par[logN][N], inv10[N];
int storelca[logN][N];
vector<int> concen[N];
vector<pair<int, int> > con[N];

inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int x, ll y){
	int ret = 1 % mod;
	for(;y; y >>= 1, x = mul(x, x)) if(y & 1) ret = mul(ret, x);
	return ret;
}

int getSizes(int s, int p){
    tree[s] = 1;
    for(auto it : con[s]){
    	int v = it.first;
    	if(v != p && !vis[v]) tree[s] += getSizes(v, s);
    }
    return tree[s];
}

int gc(int s, int p, int n){
    for(auto it : con[s]){
    	int v = it.first;
        if(v != p && !vis[v]){
            if(2 * tree[v] > n) return gc(v, s, n);
        }
    }
    return s;
}

int decompose(int s, int p, int l){
    int root = gc(s, p, getSizes(s, p));
    parcen[root] = p;
    if(p > 0) concen[p].pb(root), concen[root].pb(p);
    vis[root] = 1;
    for(auto it : con[root]){
    	int v = it.first;
        if(!vis[v]) decompose(v, root, l + 1);
    }
    return root;
}

void dfs_original(int s, int p, int d, int w){
	h1[s] = add(mul(h1[p], 10), w);
	if(d) h2[s] = add(mul(w, pow10[d - 1]), h2[p]);
	depth[s] = d;
	par[0][s] = p;
	for(auto it : con[s]) if(it.first != p) dfs_original(it.first, s, d + 1, it.second);
}

void pre_original(int n){
	for(int d = 1; d < logN; d++)
		for(int i = 1; i <= n; i++) par[d][i] = par[d - 1][par[d - 1][i]];
}

inline int lca(int a, int b){
    if(depth[a]<depth[b])
        swap(a,b);
    int l = depth[a]-depth[b];
    for(int i = 0;i<logN;i++) if(l&(1<<i)) a = par[i][a];    
    if(a==b) return a;
    for(int i = logN-1;i>=0;i--)
        if(par[i][a]!=par[i][b])
            a = par[i][a],b = par[i][b];
    return par[0][a];
}
int modInverse(int a, int m){
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}
inline int inv(int x){ return modInverse(x, mod);}

inline pair<int, int> get_num(int i, int j, int cnt){
	int k = storelca[cnt][j];
	int l1 = depth[k], l2 = depth[j];
	int d = l2 - l1;
	return {depth[i] + l2 - 2 * l1, add(sub(h1[j], mul(pow10[d], h1[k])), mul(mul(pow10[d], sub(h2[i], h2[k])), inv10[l1]))};
}
inline int get_length(int i, int j){
	return depth[i] + depth[j] - 2 * depth[lca(i, j)];
}
vector<int> cnt1[N], cnt2[N];
inline int get(vector<int> & v, int x){
	return upper_bound(v.begin(), v.end(), x) - upper_bound(v.begin(), v.end(), x - 1);
}
int main(){
	int n;
	sd(n); sd(mod);
	if(mod == 1){
		printf("%lld\n", n * 1ll * (n - 1));
		return 0;
	}
	pow10[0] = inv10[0] = 1;
	int i10 = (inv(10 % mod) % mod + mod) % mod;
	
	for(int i = 1; i < N; i++){
		pow10[i] = mul(pow10[i - 1], 10);
		inv10[i] = mul(inv10[i - 1], i10);
	}
	for(int i = 1; i < n; i++){
		int u, v, w;
		sd(u); sd(v); sd(w);
		u++; v++; w %= mod;
		con[u].pb({v, w});
		con[v].pb({u, w});
	}
	dfs_original(1, 0, 0, 0);
	pre_original(n);
	int centroid = decompose(1, 0, 0);
	for(int i = 1; i <= n; i++){
		int node = i, prev = 0, cnt = 0;
		while(node){
			int k = lca(i, node), j = node; storelca[cnt++][i] = k;
			int l1 = depth[k], l2 = depth[j];
			int d = l2 - l1;
			int val = add(sub(h1[j], mul(pow10[d], h1[k])), mul(mul(pow10[d], sub(h2[i], h2[k])), inv10[l1]));
			cnt1[node].pb(val);
			if(prev) cnt2[prev].pb(val);
			prev = node;
			node = parcen[node];
		}
	}
	for(int i = 1; i <= n; i++){
		sort(cnt1[i].begin(), cnt1[i].end());
		sort(cnt2[i].begin(), cnt2[i].end());
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		int node = i, prev = 0, cnt = 0;
		while(node){
			pair<int, int> V = get_num(node, i, cnt++);
			int val = V.second, l = V.first;
			int req = mul((mod - val), inv10[l]);
			ans += get(cnt1[node], req) - get(cnt2[prev], req); //cnt1[node][req] - cnt2[prev][req];
			prev = node;
			node = parcen[node];
		}
	}
	printf("%lld\n", ans - n);
}