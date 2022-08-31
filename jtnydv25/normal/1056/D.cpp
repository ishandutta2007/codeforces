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
vector<int> child[N];
int cnt[N];

int dfs(int s){
	int leaf = child[s].empty();
	if(leaf){
		cnt[1]++;
		return 1;
	}
	int nl = 0;
	for(int v : child[s]) nl += dfs(v);
	cnt[nl]++;
	return nl;
}

int main(){
	int n; sd(n);
	for(int i = 2; i <= n; i++){
		int x; sd(x);
		child[x].push_back(i);
	}	
	dfs(1);
	int curr = 1;
	int total = 0;
	for(int i = 1; i <= n; i++){
		total += cnt[i];
		while(total >= curr){
			printf("%d ", i);
			curr++;
		}
	}
	printf("\n");
}