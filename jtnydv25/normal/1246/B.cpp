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

const int N = 100005;
int a[N], cnt[N], factor[N];
const ll INF = 1e18;
inline ll mul(ll x, ll y){
	if(x == 0 || y == 0) return 0;
	if(x >= 1 + (INF - 1) / y) return INF;
	return x * y;
}
inline ll power(ll x, int k){
	ll ret = 1;
	for(; k; k >>= 1, x = mul(x, x)) if(k & 1) ret = mul(ret, x);
	return ret;
}

int gc(int n, int k){
	return (n - 1) / k + 1;
}
int main(){
	int n = 100000, k = 100;
	sd(n); sd(k);
	for(int i = 2; i < N; i++) if(!factor[i])
		for(int j = i; j < N; j += i) factor[j] = i;
	for(int i = 1; i <= n; i++) sd(a[i]), cnt[a[i]]++;
	ll ans = 0;
	for(int i = 1; i < N; i++){
		int mnf = 1, x = i;
		while(x != 1){
			int p = factor[x], e = 0;
			while(x % p == 0){
				x /= p;
				e++;
			}
			int z = gc(e, k);
			for(int j = 0; j < z; j++) mnf *= p;
		}
		for(int l = mnf; l < N; l += mnf){
			ll val = power(l, k);
			if(val >= 1e10 + 5) continue;
			ll other = val / i;
			if(other < N){
				if(other == i){
					ans += cnt[i] * (ll) (cnt[other] - 1);
				} else{
					ans += cnt[i] * (ll) cnt[other];
				}
			}
		}
	}
	printf("%lld\n", ans / 2);
}