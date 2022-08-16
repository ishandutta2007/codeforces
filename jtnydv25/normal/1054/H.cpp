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

const int mod = 490019;
const int p1 = 499;
const int p2 = 491;
const int g = 2;

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
const int N =500005;
int pw[N], invpw[N];
int storeMod[N];
void init(){
	pw[0] = 1;
	invpw[1] = 0;
	for(int i = 1; i < mod - 1; i++){
		pw[i] = mul(g, pw[i - 1]), invpw[pw[i]] = i;
		storeMod[i] = i % (p2);
	}
}

int F[1024][1024];
int G[1024][1024];

int eval(int v[], int x, int size){
	long long ret = 0;
	for(int i = size - 1; i >= 0; i--){
		ret = ret * x + v[i];
		if(i & 1) ret %= mod;
	}
	return ret % mod;
}

void eval2(int v[], vector<int> & x, int ind, int size){
    int i = 0;
	for(int it : x) G[i++][ind] = eval(v, it, size);
}

long long ans[N];
const int phi = mod - 1;
inline int add2(int a, int b){
	a += b; if(a >= phi) a -= phi;
	return a;
}

const int P1 = 2 * p1;
void eval(vector<int> a){
	for(int i = 0; i < a.size(); i++)
		F[i % P1][i/P1] = a[i];

	vector<int> inputs;

	for(int i = 0; i < p2; i++){
		inputs.push_back(pw[i * P1]);
	}

	for(int i = 0; i < P1; i++){
		eval2(F[i], inputs, i, p2);
	}
// 	cout << clock() / (double) CLOCKS_PER_SEC<<endl;
	ans[0] = a[0];
	for(int x = 1; x < mod; x++){
		int alpha = invpw[x];
		int sm = 0;
		int ind = storeMod[invpw[x]];
		for(int i = 0; i < P1; i++){
			ans[x] += G[ind][i] * (ll) pw[sm];
			sm = add2(sm, alpha);
		}
		ans[x] %= mod;
	}
// 	cout << clock() / (double) CLOCKS_PER_SEC<<endl;
}

vector<int> a, b;

vector<int> poly;
int main(){
	init();
	int n = 100000, m = 100000, c = 486764;
	scanf("%d %d %d", &n, &m, &c);
	poly.resize(mod);
	a.resize(n);
	b.resize(m);
	for(int i = 0; i < a.size(); i++){
		a[i] = i;
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < b.size(); i++){
		b[i] = i;
		scanf("%d", &b[i]);
	}

	for(int i = 0; i < a.size(); i++) poly[(i * (ll) i) % (mod - 1)] = add(poly[(i * (ll) i) % (mod - 1)], a[i]);
	eval(poly);
	int ret = 0;
	for(int j = 0; j< m; j++){
		// trace(j, b[j], invpw[powr(c, j * (ll) j * (ll) j)]);
		ret = add(ret, mul(b[j], ans[powr(c, j * (ll) j * (ll) j)]));
	}
	printf("%d\n", ret);
}