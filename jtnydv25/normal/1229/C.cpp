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

const int N = 100005;
set<pii> st[N];
ll cnt[N];
ll ans;
int deg[N];
int lt[N];

int val[N];

void update(int u, int lu){
	ans -= lt[u] * (ll) (deg[u] - lt[u]);
	lt[u] = lu;
	ans += lt[u] * (ll) (deg[u] - lt[u]);
}
set<int> bigNodes;

vector<int> con[N], conbig[N];
const int K = 105;
int main(){
	int n, m; sd(n); sd(m);
	iota(val, val + N, 0);
	for(int i = 1; i <= m; i++){
		int u, v;
		sd(u); sd(v);
		if(u > v) swap(u, v);
		deg[u]++;
		deg[v]++;
		lt[v]++;
		con[u].push_back(v);
		con[v].push_back(u);
	}

	for(int i = 1; i <= n; i++){
		ans += lt[i] * (ll) (deg[i] - lt[i]);
		if(deg[i] > K){
			for(auto it : con[i]) conbig[it].push_back(i);
		}
		else{
			for(auto it : con[i]) st[it].insert({-i, i});
		}
	}

	int q;
	sd(q);
	printf("%lld\n", ans);
	for(int i = 1; i <= q; i++){
		int v; sd(v);
		// val[v] = n + i
		update(v, deg[v]);
		for(auto it : st[v]){
			int u = it.S;
			if(val[u] < val[v]) break;
			update(u, lt[u] - 1);
		}

		for(auto u : conbig[v]){
			if(val[u] > val[v]){
				update(u, lt[u] - 1);
			}
		}
		if(deg[v] <= K){
			for(auto it : con[v]){
				st[it].erase({-val[v], v});
				st[it].insert({-(n + i), v});
			}
		}
		val[v] = n + i;
		printf("%lld\n", ans);
	}
}