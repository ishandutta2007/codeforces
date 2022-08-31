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
int a[N];
vector<pii> vec;
vector<int> queries[N];
int K[N], pos[N];
int ans[N];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
int main(){
	int n, m; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		vec.push_back({a[i], i});
	}
	sort(all(vec), [](const pii & a, const pii & b){
		return a.F > b.F || (a.F == b.F && a.S < b.S);
	});
	 sd(m);
	for(int i = 0; i < m; i++){
		sd(K[i]); sd(pos[i]);
		queries[K[i]].push_back(i);
	}
	ordered_set os;
	for(int i = 1; i <= n; i++){
		pii P = vec[i - 1];
		os.insert(P.S);
		for(auto it : queries[i]){
			ans[it] = a[*os.find_by_order(pos[it] - 1)];
		}
	}
	for(int i = 0; i < m; i++) printf("%d\n", ans[i]);
}