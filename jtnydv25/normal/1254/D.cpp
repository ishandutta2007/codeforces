#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int mod = 998244353;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

const int N = 150005;
#define LSOne(S) (S & (-S))
using namespace std;

struct range_bit{
	vector<int> B1, B2;
	int n;
	range_bit(){

	}
	range_bit(int n) : n(n), B1(n + 10), B2(n + 10){
	}
	int query(vector<int> & ft, int b) {
		int sum = 0;
		for (; b; b -= LSOne(b)) sum = add(sum, ft[b]);
		return sum;
	}

	int query(int b) {
		return sub(mul(b, query(B1, b)), query(B2, b));
	}
	int range_query(int i, int j)    {
		return sub(query(j), query(i - 1));
	}

	void update(vector<int> & ft, int k, ll v) {
		for (; k <= n; k += LSOne(k)) ft[k] = add(ft[k], v);
	}

	void range_update(int i, int j, int v)   {
		update(B1, i, v);
		update(B1, j + 1, sub(0, v));
		update(B2, i, mul(v, i - 1));
		update(B2, j + 1, mul(j, sub(0, v)));
	}
};

const int CUTOFF = 111;
const int logN = 20;
vector<int> con[N];
int par[logN][N],depth[N];
int up[N], updown[N];
int subtree[N], st[N], en[N], timer = 0;
int heavy[N];
void dfs(int s = 1, int d = 1, int p = 0){
    depth[s] = d;
    par[0][s] = p;
	st[s] = ++timer;
	subtree[s] = 1;
    for(int v:con[s])
        if(v!=p){
            dfs(v,d+1,s);
			subtree[s] += subtree[v];
		}
	en[s] = timer;
}

int lca(int a, int b){
    if(depth[a]<depth[b])
        swap(a,b);
    int l = depth[a]-depth[b];
    for(int i = 0;i<logN;i++) if(l&(1<<i)) a = par[i][a];    
    if(a==b) return a;
    assert(depth[a] == depth[b]);
    for(int i = logN-1;i>=0;i--)
        if(par[i][a]!=par[i][b])
            a = par[i][a],b = par[i][b];
    return par[0][a];
}

int getKth(int x, int k){
	for(int i = 0; i< logN; i++) if(k >> i & 1) x = par[i][x];
	return x;
}

void dfs2(int s = 1, int p = 0){
	heavy[s] = sz(con[s]) >= CUTOFF;
	up[s] = (heavy[p] ? p : up[p]);
	if(up[s] != 0){
		updown[s] = getKth(s, depth[s] - depth[up[s]] - 1);
	}
	for(int v : con[s]) if(v != p) dfs2(v, s);
}

void pre(int n){
    for(int j = 1;j<logN;j++)
        for(int i = 1;i<=n;i++)
            par[j][i] = par[j-1][par[j-1][i]];
}

int n, q;
range_bit R1, R2;
int self[N];
int invn;
int f[N];
void update(int v, int x){
	// trace(v, x);
	self[v] = add(self[v], x);
	// R2.range_update(st[v], st[v], mul(f[v], x));
	int d = mul(f[v], x);
	R1.range_update(1, n, d);
	R1.range_update(st[v], en[v], sub(0, d));
	
	if(!heavy[v]){
		int p = par[0][v];
		for(int c : con[v]) if(c != p){
			R1.range_update(st[c], en[c], mul(sub(1, f[c]), x));
		}
	}
}

int get(int x){
	int ret = add(self[x], R1.range_query(st[x], st[x]));
	// trace(ret);
	// ret = add(ret, sub(R2.range_query(1, n), R2.range_query(st[x], en[x])));
	int curr = up[x], curr_c = updown[x];
	while(curr){
		ret = add(ret, mul(self[curr], sub(1, f[curr_c])));
		curr_c = updown[curr];
		curr = up[curr];
	}
	return ret;
}
int main(){
	sd(n); sd(q);
	invn = inv(n);
	R1 = range_bit(n);
	R2 = range_bit(n);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		sd(u);
		sd(v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	dfs();
	pre(n);
	dfs2();
	for(int i = 1; i <= n; i++){
		f[i] = mul(subtree[i], invn);
		// trace(i, up[i], updown[i]);
	}
	while(q--){
		int u, v, d;
		sd(u); sd(v);
		if(u==1){
			sd(d);
			update(v, d);
		} else{
			printf("%d\n", get(v));
		}
	}
}