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
const ll INF = 2e6;
int main(){
	int t; sd(t);
	while(t--){
		map<int, int> freq;
		int n, p; sd(n); sd(p);
		for(int i = 0; i < n; i++){
			int k; sd(k); freq[k]++;
		}
		if(p == 1){
			printf("%d\n", n % 2);
			continue;
		}
		vector<pii> vec;
		for(auto it : freq) vec.push_back(it);
		reverse(all(vec));
		ll curr = 0;
		int old = 1e6 + 10;
		int absdiff = 0;
		for(auto it : vec){
			// if(n == 4) trace(it);
			if(curr != 0 && curr != INF){
				if(old - it.F >= 30){
					curr = INF; 
				} else{
					for(int r = 0; r < old - it.F; r++){
						curr = min(INF, p * curr);
					}
				}
			}

			old = it.F;
			if(curr == INF){
				absdiff = sub(absdiff, mul(powr(p, it.F), it.S));
				continue;
			}

			if(it.S <= curr){
				curr -= it.S;
				absdiff = sub(absdiff, mul(powr(p, it.F), it.S));
				continue;
			}

			if((it.S + curr) & 1){
				absdiff = powr(p, it.F);
				curr = 1;
			} else{
				absdiff = 0;
				curr = 0;
			}
			// trace(it, absdiff);
		}
		printf("%d\n", absdiff);
	}
}