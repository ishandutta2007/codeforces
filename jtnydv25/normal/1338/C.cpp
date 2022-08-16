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

const int N = 30;

ll get(int k, ll n){
	if(k == 0) return 0;
	ll V = 1LL << (k - 2);
	if(n < V) return get(k - 2, n);
	if(n < 2 * V) return (2LL << (k - 2)) + get(k - 2, n - V);
	if(n < 3 * V) return (3LL << (k - 2)) + get(k - 2, n - 2 * V);
	return (1LL << (k - 2)) + get(k - 2, n - 3 * V);
}

ll query(ll n){
	n--;
	int t = n % 3;
	n /= 3;
	int k = 0;
	ll pos = 0;
	while(pos + (1LL << k) <= n){
		pos += 1LL << k;
		k += 2;
	}
	n -= pos;
	if(t==0) return (1LL << k) + n;
	ll B = (1LL << (k + 1)) + get(k, n);
	if(t == 1) return B;
	return ((1LL << k) + n) ^ B;
}

int main(){
	int t; sd(t);
	while(t--){
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", query(n));
	}	
}