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

const int N = 200005;
ll a[N];
int n;

inline ll getBest(ll x, ll p){
	if(x < p) return p - x;
	ll t = x % p;
	return min(t, p - t);
}

ll get(ll p){
	ll ret = 0;
	for(int i = 1; i <= n; i++){
		ret += getBest(a[i], p);
		if(ret >= n) return n;
	}
	return ret;
}

const int MX = 100;
int prime[MX];

vector<ll> factorize(ll t){
	vector<ll> vec;
	for(ll p = 2; p * p <= t; p++){
		if(t % p == 0){
			vec.push_back(p);
			while(t % p == 0) t /= p;
		}
	}
	if(t != 1) vec.push_back(t);
	return vec;
}
// mt19937_64 for 64 bit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int getRand(int x, int y){
	return uniform_int_distribution<int>(x, y)(rng);
}
const int ITER = 20;
int main(){
	sd(n);
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	ll ret = n;
	fill(prime + 2, prime + MX, 1);
	for(int i = 2; i < MX; i++) if(prime[i]){
		ret = min(ret, get(i));
		for(int j = i; j < MX; j += i) prime[j] = 0;
	}

	for(int i = 0; i < ITER; i++){
		int pos = getRand(1, n);
		ll v = a[pos];
		vector<ll> vec = factorize(v);
		for(auto it : vec) ret = min(ret, get(it));
		vec = factorize(v+1);
		for(auto it : vec) ret = min(ret, get(it));
		if(v >= 2){
			vec = factorize(v-1);
			for(auto it : vec) ret = min(ret, get(it));
		}
	}
	printf("%lld\n", ret);
}