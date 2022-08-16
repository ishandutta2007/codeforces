#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

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
const int N = 1000006;
char s[N];
const int base = 31;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ull mod = 100000000LL * 100000000LL + 61;
const long double invMOD = 1. / mod;
inline ull add(ull x, ull y){ x += y; if(x >= mod) x -= mod; return x;}
inline ull sub(ull x, ull y){ x -= y; if(ll(x) < 0) x += mod; return x;}
inline ll mul(ull a, ull b) {
	ull y = ull(ld(a) * ld(b) * invMOD + ld(1) / 2);
	ull r = a * b - y * mod;
	if(ll(r) < 0)
		r += mod;
	return r;
}

inline ull powr(ull a, ull b){
	ull x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline ull inv(ull a){ return powr(a, mod - 2);}

ull powers[N], H[N], revH[N];
ull invPowers[N];

ull getHash(int i, int j){
	return sub(H[j], mul(H[i - 1], powers[j - i + 1]));
}

ull getRevHash(int i, int j){
	return sub(revH[i], mul(revH[j + 1], powers[j - i + 1]));
}

bool isPal(int i, int j){
	return getHash(i, j) == getRevHash(i, j);
}

int main(){
	int t;
	sd(t);
	powers[0] = 1;
	for(int i = 1; i < N; i++) powers[i] = (powers[i - 1] * base) % mod;
	while(t--){
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int mx = 0;
		revH[n + 1] = 0;
		for(int i = 1; i <= n; i++){
			H[i] = (H[i - 1] * base + s[i] - 'a' + 1) % mod;
		}

		for(int i = n; i >= 1; i--){
			revH[i] = (revH[i + 1] * base + s[i] - 'a' + 1) % mod;
		}

		for(int i = 1; i <= n / 2; i++){
			if(s[i] != s[n + 1 - i]){
				break;
			}
			mx = i;
		}
		int lft = mx, rgt = mx;
		int ans = 2 * mx;
		for(int l = 0; l <= mx; l++){
			for(int i = l + 1; i <= n - l; i++){
				if(i + l > ans && isPal(l + 1, i)){
					ans = i + l;
					lft = i, rgt = l;
				}
			}
			for(int j = n - l; j > l; j--) if(l + n - j + 1 > ans && isPal(j, n - l)){
				ans = l + n - j + 1;
				lft = l; rgt = n - j + 1;
			}
		}
		for(int i = 1; i <= lft; i++) printf("%c", s[i]);
		for(int i = n - rgt + 1; i <= n; i++) printf("%c", s[i]);
		printf("\n");
	}
}