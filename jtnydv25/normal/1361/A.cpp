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

int main(){
	int n, m; sd(n); sd(m);
	vector<vector<int>> adj(n + 1);
	vector<int> t(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; sd(u); sd(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; i++) sd(t[i]);
	vector<int> perm(n); iota(all(perm), 1);
	sort(all(perm), [&](int i, int j){return t[i] < t[j];});
	vector<int> done(n + 1);
	for(int i : perm){
		vector<int> vec;
		for(int j : adj[i]) if(done[j]) vec.push_back(t[j]);
		sort(all(vec));
		vec.resize(unique(all(vec)) - vec.begin());
		int mex = -1;
		for(int j = 0; j < sz(vec); j++) if(j + 1 != vec[j]){
			mex = j + 1;
			break;
		}
		if(mex == -1) mex = sz(vec) + 1;
		if(t[i] != mex){
			// trace(i);
			printf("-1\n");
			return 0;
		}
		done[i] = 1;
	}

	for(int i : perm) printf("%d ", i); return 0;
}