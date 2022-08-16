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
const int N = 100005;
int deg[N];
vector<int> leaves;
int main(){
	int n;
	sd(n);
	for(int i = 1; i < n; i++){
		int u, v;
		sd(u); sd(v);
		deg[u] ++; deg[v]++;
	}
	int cnt = 0;
	int mxdeg = 0;
	int root = 0;
	for(int i = 1; i <= n; i++){
		if(deg[i] > mxdeg){
			mxdeg = deg[i];
			root = i;
		}
		if(deg[i] == 1) leaves.push_back(i);
		if(deg[i] > 2) cnt++;
	}
	if(cnt > 1){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	int m = 0;
	for(auto it : leaves) if(it != root) m++;
	printf("%d\n", m);
	for(auto it : leaves){
		if(it != root) printf("%d %d\n", root, it);
	}
}