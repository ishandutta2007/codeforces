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
int a[N], b[N], c[N], d[N], perm[N];
ll bit[N];
void add(int x, int i){
	for(; x < N; x += (x & (-x))) bit[x] += i;
}

ll get(int x){
	ll ret = 0;
	for(; x; x -= (x & (-x))) ret += bit[x];
	return ret;
}

ll get(int l, int r){
	return get(r) - get(l - 1);
}

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		perm[i] = i;
	}
	for(int i = 1; i <= n; i++){
		sd(b[i]); d[b[i]] = i;
	}
	ll ans = 0;	
	
	for(int i = 1; i <= n; i++){
		ans += get(d[a[i]] + 1, n) > 0;
		add(d[a[i]], 1);
	}

	printf("%lld\n", ans);
}