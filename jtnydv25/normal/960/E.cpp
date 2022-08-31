#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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

const int mod = 1e9 + 7;

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

const int N = 200005;
int tree[N], parity[2][N], depth[N];
int v[N];
vector<int> con[N];
vector<int> child[N];
void dfs(int s = 1, int p = 0){
	depth[s] = depth[p] ^ 1;
	parity[depth[s]][s]++;
	tree[s] = 1;
	for(int v : con[s]){
		if(v != p){
			dfs(v, s);
			tree[s] += tree[v];
			for(int j = 0; j < 2; j++)
				parity[j][s] += parity[j][v];
			child[s].push_back(v);
		}
	}
}

vector<pii> vec;
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(v[i]);
		if(v[i] < 0) v[i] += mod;
	}

	for(int i = 1; i < n; i++){
		int a, b;
		sd(a); sd(b);
		con[a].push_back(b);
		con[b].push_back(a);
	}
	dfs();
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int tsame = 1, topp = 0;
		int ans1 = n - 1;
		int total = tree[i]; 
		for(int v : child[i]){
			int same = parity[depth[i]][v], opp = parity[depth[i] ^ 1][v];
			int sz = tree[v];
			ans1 = add(ans1, mul(sub(same, opp), sub(n, tree[v])));
		}
		int same = parity[depth[i]][1] - parity[depth[i]][i], opp = parity[depth[i] ^ 1][1] - parity[depth[i] ^ 1][i];
		int sz = n - tree[i];
		ans1 = add(ans1, mul(sub(same, opp), tree[i]));
		ans = add(ans, mul(v[i], ans1));
		ans = add(ans, v[i]);
	}
	printf("%d\n", ans);
}