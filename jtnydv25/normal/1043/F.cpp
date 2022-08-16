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

const int N = 3.1e5;
int factor[N], mu[N];
void pre_prime(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++) if(!factor[i])factor[i] = i;
    mu[1] = 1;
    for(int i = 2;i < N; i++){
    	int p = factor[i], x = i/p;
    	mu[i] = (x % p == 0) ? 0 : -mu[x];
    }
}

int mod;

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

int f[N], cnt[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool is_prime(int n){
	for(int i = 2; i * i <= n; i++) if(n % i == 0) return 0;
	return 1;
}

int getRandPrime(){
	int x = uniform_int_distribution<int>(800000000, 1000000000)(rng);
	while(!is_prime(x)) x++;
	return x;
}

int perm[N], fact[N], invfact[N];

void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}

inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int get(int k){
	int ans =0;
	for(int i = 1; i < N; i++){
		int d = perm[i];
		if(f[d] < k) return ans;
		if(mu[d] == 1){
			ans = add(ans, C(f[d], k));
		} else if(mu[d] == -1)ans = sub(ans, C(f[d], k));
	}
	return ans;
}
const int INF = 1e9;
int experiment(){
	mod = getRandPrime();
	pre();
	for(int k = 1; k < N; k++) if(get(k)) return k;
	return INF;
}
const int ITER = 5;
int main(){
	pre_prime();
	int n; sd(n);
	int g = 0;
	for(int i = 1; i <= n; i++){
		int x;
		sd(x); cnt[x]++;
		g = __gcd(x, g);
	}	
	if(g != 1){
		printf("-1\n");
		return 0;
	}
	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i) f[i] += cnt[j];
		perm[i] = i;
	}

	sort(perm + 1, perm + N, [](int i, int j){return f[i] > f[j];});
	int ans = INF;
	for(int i = 0; i < ITER; i++){
		int val =experiment();
		ans = min(ans, val);
	}	

	printf("%d\n", ans == INF ? -1 : ans);
}