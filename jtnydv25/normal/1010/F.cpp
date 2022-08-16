#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
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

const int g = 3, mod = 998244353, p = 998244353;
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

const int MX = 18;
int W[1 << MX], invW[1 << MX]; // max polynomial input/output -> (1 << MX)
int maxn;
void precompute_powers(){
	int p2 = p - 1, MAXN = 0;
	while(p2 % 2 == 0){
		p2 >>= 1;
		MAXN ++;
	}
	MAXN = min(MAXN, MX);
	int g1 = powr(g, (p - 1) >> MAXN);
	maxn = 1 << MAXN;
	int st = 1;
	for(int i = 0; i < maxn; i++){
		W[i] = st;
		st = mul(st, g1);
	}
	for(int i = 0; i < maxn; i++){
		invW[i] = (i == 0) ? 1 : W[maxn - i];
	}
}

void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        for (int i=0; i<n; i+=len) {
            int ind = 0,ADD = maxn/len;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = mul(a[i+j+len/2], (invert?invW[ind]:W[ind]));
                a[i+j] = add(u, v);
                a[i+j+len/2] = sub(u, v);
                ind += ADD;
            }
        }
    }
    if (invert){
    	int invn = inv(n);
    	for (int i=0; i<n; ++i) a[i] = mul(a[i], invn);
    }
}

const ll mod2 = 4ll * mod * (ll) mod;

ll temp[200005];

vi naive_mul(vi & a, vi & b){
	int sz = a.size() + b.size() - 1;
	vi c(sz);
	for(int i = 0; i < sz; i++) temp[i] = 0;
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < b.size(); j++){
			temp[i + j] += a[i] * (ll) b[j];
			if(temp[i + j] >= mod2) temp[i + j] -= mod2;
		}
	for(int i = 0; i < sz; i++) c[i] = temp[i] % mod;
	return c;
}

vi mul(vi a, vi b){
	ll time_1 = (a.size() + b.size()) * 100, time_2 = a.size() * (ll) b.size();
	if(time_2 < time_1){
		return naive_mul(a, b);
	}
	int sz = a.size() + b.size() - 1;
	int k = 0;
	while((1 << k) < sz) k++;
	a.resize(1 << k); b.resize(1 << k);
	fft(a, 0); fft(b, 0);
	for(int i = 0; i < (1 << k); i++)
		a[i] = mul(a[i], b[i]);
	fft(a, 1);
	a.resize(sz);
	return a;
}

const int N = 100005;
vector<int> con[N];
vector<int> T[N];
int sz[N];

void dfs(int s = 1, int p = 0){
	sz[s] = 1;
	for(int v : con[s]) if(v != p){
		dfs(v, s);
		sz[s] += sz[v];
	}
}
vi X = {0, 1};
const int Delta = 3005;

vi add(vi a, vi b){
	if(a.size() < b.size()){
		for(int i = 0; i < a.size(); i++) b[i] = add(a[i], b[i]);
		return b;
	}
	else{
		for(int i = 0; i < b.size(); i++) a[i] = add(a[i], b[i]);
		return a;	
	}
}

vi sub(vi a, vi b){ 
    vi ret(max(a.size(), b.size()));
    for(int i = 0; i < ret.size(); i++){
        ret[i] = sub(i < a.size() ? a[i] : 0, i < b.size() ? b[i] : 0);
    }
    return ret;
}

vi Zero = {0};
vi force_eval(pair<int, pair<vi, vi>> & inp){
	return add(inp.F == -1 ? Zero : mul(T[inp.F], inp.S.F), inp.S.S);
}

int ind[N];
pair<int, pair<vi, vi> > st[N];
int dfs2(int s = 1, int p = 0){
	if(s == 0){
		return 0;
	}

	int cnt = 0;

	vector<int> children;
	for(int v : con[s]) if(v != p){
		children.push_back(v);
	}

	if(children.empty()){
		T[s] = {1, 1};
		st[s] = {s, {{1}, {0}}};
		return s;
	}

	if(children.size() == 1) children.push_back(0);	
	if(sz[children[0]] > sz[children[1]]) swap(children[0], children[1]);
	int got = dfs2(children[0], s);
	vi to_add = force_eval(st[got]);
	reverse(to_add.begin(), to_add.end());
	to_add.push_back(0);
	reverse(to_add.begin(), to_add.end());
	int ret = dfs2(children[1], s);
	st[ret].S.F = mul(st[ret].S.F, to_add);
	st[ret].S.S = mul(st[ret].S.S, to_add);
	st[ret].S.S[0] = add(st[ret].S.S[0], 1);

	if(st[ret].S.F.size() >= Delta){
		T[s] = force_eval(st[ret]);
		st[ret].S.F.clear(); st[ret].S.F.shrink_to_fit();
		st[ret].S.S.clear(); st[ret].S.S.shrink_to_fit();
		st[ret] = {s, {{1}, {0}}};
	}

	return ret;
}


int main(){
	precompute_powers();
	T[0] = {1};
	st[0] = {{0}, {{1}, {0}}};
	int n = 100000; 
	sd(n);
	ll x = 1e9;
	scanf("%lld", &x);
	for(int i = 1; i < n; i++){
		int u, v;
		if(i <= n){u = i + 1; v = i;}
		else{u = i - n/2, v = i + 1;}
		sd(u); sd(v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	dfs();
	pair<int, pair<vi, vi> > ans = st[dfs2()];
	vi vec = force_eval(ans);
	x %= mod;
	int curr = 1;
	int ret = 0;
	for(int i = 1; i <= n; i++){
		ret = add(ret, mul(curr, vec[i]));
		curr = mul(curr, x + i);
		curr = mul(curr, inv(i));
	}
	printf("%d\n", ret);
}