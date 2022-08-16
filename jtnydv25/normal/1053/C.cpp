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
#define TRACE(...)
#endif

#define LSOne(S) (S & (-S))

const int N = 2e5 + 10;

template<class T>
struct range_bit{
	T B1[N];

	T query(int b) {
	    T sum = 0;
	    for (; b; b -= LSOne(b)) sum += B1[b];
	    return sum;
	}

	T range_query(int i, int j)    {
	    return query(j) - query(i - 1);
	}

	void update(int k, T v) {
	    for (; k < N; k += LSOne(k)) B1[k] += v;
	}
};

range_bit<ll> bit1, bit2;
range_bit<long double> bit3;

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

int a[N], w[N];
long double get(int l, int r, int pos){
	// l .. pos -> sum(wi * (pos - bi))
	// pos + 1 ... r -> sum(wi * (bi - pos))
	return bit3.range_query(pos + 1, r) - bit3.range_query(l, pos) + a[pos] * (long double) (bit1.range_query(l, pos)
	 - bit1.range_query(pos + 1, r));
}

int get_mod	(int l, int r, int pos){
	ll x1 = bit2.range_query(pos + 1, r) - bit2.range_query(l, pos);
	x1 %= mod;
	x1+= mod;
	x1 %= mod;
	ll x2 = bit1.range_query(l, pos)- bit1.range_query(pos + 1, r);
	x2 %= mod;
	x2+= mod;
	x2 %= mod;
	return add(x1, mul(a[pos], x2));
}

int main(){
	int n, q;
	sd(n);sd(q);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		a[i] -= i;
	}
	for(int i = 1; i <= n; i++){
		sd(w[i]);
		bit1.update(i, w[i]);
		bit2.update(i, mul(w[i], a[i]));
		bit3.update(i, a[i] * (ll) w[i]);
	}

	while(q--){
		int x, y; sd(x); sd(y);
		if(x < 0){
			x *= -1;
			bit1.update(x, y - w[x]);
			bit2.update(x, mul(y, a[x]) - mul(w[x], a[x]));
			bit3.update(x, (y - w[x]) * (ll)a[x]);
			w[x] = y;
		} else{
			int lo = x, hi = y;
			ll total_sum = bit1.range_query(x, y);
			while(lo < hi){
				int mid = (lo + hi) >> 1;
				if(2 * bit1.range_query(x, mid) >= total_sum){
					hi = mid;
				} else lo = mid + 1;
			}
			if(x == lo){
				printf("%d\n", get_mod(x, y, x));
			}
			else if(get(x, y, lo) > get(x, y, lo - 1)){
				printf("%d\n", get_mod(x, y, lo - 1));
			} else printf("%d\n", get_mod(x, y, lo));
		}
	}

}