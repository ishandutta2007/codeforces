#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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


const int N = 100005;
const int logN = 18;
vector<int> con[N];

int paR[logN][N],depth[N];

void dfs(int s = 1, int p = 0){
    depth[s] = depth[p] + 1;
    paR[0][s] = p;
    for(int v:con[s])
        if(v!=p)
            dfs(v, s);
}

void pre(int n){
    for(int j = 1;j<logN;j++)
        for(int i = 1;i<=n;i++)
            paR[j][i] = paR[j-1][paR[j-1][i]];
}

int lca(int a, int b){
    if(depth[a]<depth[b])
        swap(a,b);
    int l = depth[a]-depth[b];
    for(int i = 0;i<logN;i++) if(l&(1<<i)) a = paR[i][a];    
    if(a==b) return a;
    assert(depth[a] == depth[b]);
    for(int i = logN-1;i>=0;i--)
        if(paR[i][a]!=paR[i][b])
            a = paR[i][a],b = paR[i][b];
    return paR[0][a];
}

const int M = 1e7 + 10;
const int PRIMES = 665000;
const int MAXPOWER = 25;

int freq[PRIMES][MAXPOWER];
int prime_index[M];
int factoR[M];

void pre_primes(){
	for(int i = 2; i * i < M; i++)
		if(!factoR[i])
			for(int j = i * i; j < M; j += i)
				factoR[j] = i;
	factoR[1] = 1;
	int curr = 0;
	for(int i = 1; i < M; i++){
		if(!factoR[i]){
			prime_index[i] = ++curr;
		}
	}
	for(int i = 1; i < M; i++) if(!factoR[i]) factoR[i] = i;
}

int a[N];
vector<pii> factorization[N];
int sz[N];

int x[N], U[N], V[N], LCA[N], b[N];

set<int> to_find[N];
map<int, int> ans[N];

inline void addsub(int i, int r){
	for(auto it : factorization[i]) freq[it.F][it.S] += r;
}

inline int get(int num){
	int ret = 1;
	while(num != 1){
		int p = factoR[num];
		int pwr = 0;
		int pind = prime_index[p];
		while(num % p == 0){
			num /= p;
			pwr++;
		}
		
		for(int j = 0; j <= pwr; j++)
			ret = mul(ret, powr(p, j * freq[pind][j]));

		int sm = 0;
		for(int j = pwr + 1; j < MAXPOWER; j++) sm += freq[pind][j];
		ret = mul(ret, powr(p, pwr * sm));
	}
	return ret;
}

void dfs2(int s = 1, int p = 0){
	addsub(s, 1);
	for(int num : to_find[s]){
		ans[s][num] = get(num);
	}	

	for(int v : con[s]) if(v != p) dfs2(v, s);
	addsub(s, -1);
}

inline int getans(int id){
	int val = inv(ans[LCA[id]][x[id]]);
	return mul(__gcd(b[LCA[id]], x[id]), mul(ans[U[id]][x[id]], mul(ans[V[id]][x[id]], mul(val, val))));
}

int main(){
	pre_primes();
	int n;
	sd(n);

	for(int i = 1; i < n; i++){
		int u, v;
		sd(u); sd(v);
		con[u].push_back(v);
		con[v].push_back(u);
	}

	for(int i = 1; i <= n; i++){
		sd(a[i]);
		b[i] = a[i];
		while(a[i] != 1){
			int p = factoR[a[i]];
			int pwr = 0;
			while(a[i] % p == 0) pwr++, a[i] /= p;
			factorization[i].push_back({prime_index[p], pwr});
		}
	}

	dfs();
	pre(n);

	int q;
	sd(q);

	for(int i = 1; i <= q; i++){
		sd(U[i]); sd(V[i]); sd(x[i]);
		LCA[i] = lca(U[i], V[i]);
		int u = U[i], v = V[i];
		to_find[U[i]].insert(x[i]);
		to_find[V[i]].insert(x[i]);
		to_find[LCA[i]].insert(x[i]);
	}

	dfs2();

	for(int i = 1; i <= q; i++) printf("%d\n", getans(i));
}