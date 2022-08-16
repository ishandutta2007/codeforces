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

const int N = 2e5 + 10;
vector<int> con[N];
int f[N];
vector<int> level;
int dep[N];
int a[N], par[N];

void dfs(int s = 1, int p = 0, int d = 0){
	dep[s] = d;
	par[s] = p;
	for(int v : con[s]) if(v != p) dfs(v, s, d + 1);
}

bool chk(){
	if(level.empty()) return 1;
	for(int i = 1; i < level.size(); i++) if(f[par[level[i]]] < f[par[level[i - 1]]]) return 0;
	return 1;
}

int main(){
	int n; sd(n);
	for(int i = 1; i < n; i++){
		int x, y; sd(x); sd(y);
		con[x].push_back(y);
		con[y].push_back(x);
	}
	dfs();
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		if((i == 1 && a[i] != 1) || (i != 1 && dep[a[i - 1]] > dep[a[i]])){
			printf("No\n");
			return 0;
		}
		f[a[i]] = i;
		if(i==1) continue;
		if(i != 2 && dep[a[i]] > dep[a[i - 1]]){
			if(!chk()){
				printf("No\n");
				return 0;
			}
			level.clear();
		}
		level.push_back(a[i]);
	}
	if(!chk()){
				printf("No\n");
				return 0;
			}
	printf("Yes\n");
	return 0;
}