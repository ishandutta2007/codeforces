#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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

int get_dist(int node, vector<int> vec){
	printf("%d %d ", 1, (int) vec.size());
	printf("%d ", node);
	for(auto it : vec) printf("%d ", it);
	printf("\n");
	fflush(stdout);
	int d;
	scanf("%d", &d);
	return d;
}

int find_node(vector<int> v, int node, int d){
	if((int)v.size() == 1) return v[0];
	int sz = ((int)v.size()) >> 1;
	vector<int> lft(v.begin(), v.begin() + sz), rgt(v.begin() + sz, v.end());
	if(get_dist(node, lft) == d) return find_node(lft, node, d);
	else return find_node(rgt, node, d);
}

int main(){
	int t;
	sd(t);
	while(t--){
		int n; sd(n);
		vector<int> v;
		for(int i = 2; i <= n; i++) v.push_back(i);
		int d = get_dist(1, v);
		int node = find_node(v, 1, d);
		v.clear();
		for(int i = 1; i <= n; i++) if(i != node) v.push_back(i);
		printf("%d %d\n", -1, get_dist(node, v));
		fflush(stdout);
	}
}