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

const int N = 200005;
int d[N], perm[N];
int nodes[N];
vector<pii> edges;
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++) scanf("%d", d + i), perm[i] = i;
	sort(perm + 1, perm + n + 1, [&](int i, int j){return d[i] > d[j];});
	int lft = 0, rgt = d[perm[1]];
	int L = rgt;
	nodes[0] = 2 * perm[1] - 1, nodes[L] = 2 * perm[1];
	for(int i = 2; i <= L; i++){
		edges.push_back({2 * perm[i] - 1, 2 * perm[i - 1] - 1});
		nodes[i - 1] = 2 * perm[i] - 1;
	}
	for(int i = L + 1; i <= n; i++) edges.push_back({2 * perm[i] - 1, nodes[0]});
	edges.push_back({2 * perm[L] - 1, nodes[L]});

	for(int i = 2; i <= L; i++){
		int dst = d[perm[i]];
		edges.push_back({2 * perm[i], nodes[i - 1 + dst - 1]});
		if(dst == rgt - i + 2){
			rgt++;
			nodes[rgt] = 2 * perm[i];
		}
	}

	for(int i = L + 1; i <= n; i++){
		int dst = d[perm[i]];
		if(dst == 1){
			edges.push_back({2 * perm[i], 2 * perm[i] - 1});
		} else{
			edges.push_back({2 * perm[i], nodes[dst - 2]});
		}
	}

	for(auto it : edges) printf("%d %d\n", it.F, it.S);
}