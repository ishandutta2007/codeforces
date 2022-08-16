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
const int N = 200005, mod = 998244353;
int p[N], pos[N];
inline int mul(int a, int b){return (a * (ll) b) % mod;}
int main(){
	int k, n; sd(n); sd(k);
	ll mx = 0;
	for(int i = 1; i <= n; i++){
		sd(p[i]);
		pos[p[i]] = i;
		if(i >= n - k + 1) mx += i;
	}
	sort(pos + n - k + 1, pos + n + 1);
	int ret = 1;
	for(int i = n - k + 1; i < n; i++){
		ret = mul(ret, pos[i + 1] - pos[i]);
	}
	printf("%lld %d\n", mx, ret);
}