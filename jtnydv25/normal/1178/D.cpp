#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())


template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<",";
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
const int N = 5005;
int factor[N], prime[N];

void solve(int n){
	vector<pii> edges;
	for(int i = 1; i <= n; i++){
		edges.push_back({i, i % n + 1});
	}

	int m = n;
	vector<bool> done(N);
	for(int i = 1; factor[m]; i++){
		if(done[i]) continue;
		edges.push_back({i, i % n + 2});
		done[i] = 1;
		done[i % n + 2] = 1;
		m++;
	}

	printf("%d\n", sz(edges));
	int deg[N];
	memset(deg, 0, sizeof deg);
	set<pii> st;
	for(auto it : edges){
		deg[it.F]++;
		deg[it.S]++;
		if(it.F > it.S) swap(it.F, it.S);
		assert(!st.count({it.F, it.S}));
		st.insert({it.F, it.S});
		assert(it.F <= n && it.F <= n && it.F != it.S);
		printf("%d %d\n", it.F, it.S);
	}
	for(int i = 1; i <= n; i++) assert(!factor[deg[i]]);
}
int main(){
	for(int i = 2; i < N; i++) if(!factor[i])
	for(int j = i * i; j < N; j += i) factor[j] = i;
	int sz = 0;
	for(int i = 2; i < N; i++) if(!factor[i]) prime[++sz] = i;
	double mx = 0;
	int t = 0;
	for(int i = 2; i <= sz; i++){
		int diff = prime[i] - prime[i - 1];
		if(diff / (double) prime[i - 1] >= .5){
			mx = max(mx, diff / (double) prime[i - 1]);
			t = i;
			// trace(t, prime[t], prime[t - 1], mx);
		}
	}
	// trace(sz);
	int n; sd(n);
	solve(n);
}