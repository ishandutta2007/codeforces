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
int main(){
	vector<ll> v;
	int n = 24, m = 35; 
	sd(n); sd(m);
	for(int i = 0; i < n; i++){
		ll x = rand() * (ll) rand() % (1LL << m);
		 scanf("%lld", &x);
		for(ll a : v){
			if(a & -a & x){
				x ^= a;
			}
		}
		if(!x) continue;
		for(ll & a : v){
			if(x & -x & a) a ^= x;
		}
		v.push_back(x);
	}
	int k = sz(v);

	vector<ll> num(m + 1);
	int z = powr(2, n - k);
	if(k < 25){
		for(int i = 0; i < (1 << k); i++){
			ll r = 0;
			for(int j = 0; j < k; j++) if(i >> j & 1) r ^= v[j];
			num[__builtin_popcountll(r)] += z;
		}
	} else{
		ll ALL  = (1LL << m) - 1;
		for(ll a : v) ALL ^= (a & -a);
		vector<map<ll, ll>> dp(m + 1), dp_old;
		dp[0][0] = 1;
		for(int i = 0; i < k; i++){
			dp_old.clear();
			dp_old = dp;
			ll now = v[i] & ALL;
			for(int ocnt = 0; ocnt < m; ocnt++){
				for(auto old : dp_old[ocnt]){
					dp[ocnt + 1][now ^ old.F] += old.S;
					dp[ocnt + 1][now ^ old.F] %= mod;
				}
			}
		}
		for(int i = 0; i <= m; i++)
			for(auto it : dp[i]){
				num[i + __builtin_popcountll(it.F)] += (it.S * z) % mod;
			}
	}
	for(int i = 0; i <= m; i++) printf("%lld ", num[i] % mod);
}