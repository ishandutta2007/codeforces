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
const int N = 100005;
vector<int> adj[N];
vector<pii> ans;

void go(int s, int p, int x){
	int num_children = sz(adj[s]) - (s != 1);
	vector<int> seq;
	int curr = x - 1;
	if(s == 1){
		for(int j = 1; j <= num_children; j++) seq.push_back(j);
	} else{
		while(sz(seq) < num_children){
			if(curr == 0) curr = x + num_children - sz(seq);
			seq.push_back(curr);
			curr--;
		}
		reverse(all(seq));
	}
	
	int pos = 0;
	for(int v : adj[s]) if(v != p){
		int val = seq[pos++];
		if(ans.back().S != val - 1) ans.push_back({s, val - 1});
		ans.push_back({v, val});
		go(v, s, val);
		if(ans.back().S != val - 1){
			ans.push_back({v, val - 1});
		}
		ans.push_back({s, val});
	}
}

int main(){
	int n; sd(n);
	for(int i = 1; i < n; i++){
		int u, v; sd(u); sd(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ans.push_back({1, 0});
	go(1, 0, 0);
	printf("%d\n", sz(ans));
	for(auto it : ans) printf("%d %d\n", it.F, it.S);
	printf("\n");
}