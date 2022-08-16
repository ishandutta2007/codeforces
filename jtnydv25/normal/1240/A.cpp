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

template<class T,class U>
ostream& operator<<(ostream& os,const map<T, U> & mp){
	os << "{";
	int i = 0;
	for(auto it : mp){
		if(i) os<<", ";
		os << it;
		i++;
	}
	os << "}";	
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
const int N = 2e5 + 10;
int p[N];
int main(){
	int t; 
	sd(t);
	while(t--){
		int n;
		ll x, y, a, b;
		ll k;
		sd(n);
		for(int i = 1; i <= n; i++){
			sd(p[i]);
			p[i] /= 100;
		}
		sort(p + 1, p + n + 1);
		reverse(p + 1, p + n + 1);
		scanf("%lld %lld %lld %lld %lld", &x, &a, &y, &b, &k);
		ll lcm = a * (b / __gcd(a, b));
		if(x < y){
			swap(x, y);
			swap(a, b);
		}
		function<ll(int)> getMax = [&](int l){
			ll num_a = l / a, num_b = l / b, num_l = l / lcm;
			num_a -= num_l;
			num_b -= num_l;
			ll ret = 0;
			// if(n==8) trace(l, num_a, num_b, num_l, a, b, lcm);
			for(int i = 1; i <= n; i++){
				if(i <= num_l) ret += (x + y) * p[i];
				if(i > num_l && i <= num_l + num_a) ret += x * p[i];
				if(i > num_l + num_a && i <= num_l + num_a + num_b) ret += y * p[i];
			}
			return ret;
		};
		int lo = 1, hi = n;
		while(lo < hi){
			int mid = (lo + hi) / 2;
			ll v = getMax(mid);
			// if(n==8)trace(k, mid, v, x, a, y, b);
			if(v >= k) hi = mid;
			else lo = mid + 1;
		}
		if(getMax(lo) < k){
			printf("-1\n");
			continue;
		}
		printf("%d\n", lo);
	}
}