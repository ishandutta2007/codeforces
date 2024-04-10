#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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

const int N = 1005;
vector<int> con[N];
int indeg[N], outdeg[N], leaf[N];
int p[N];
int main(){
	int n;
	sd(n);
	for(int i = 1; i < n; i++){
		sd(p[i + 1]);
		indeg[i + 1]++;
		outdeg[p[i + 1]]++;
		con[p[i + 1]].push_back(i + 1);
	}
	for(int i = 1; i <= n; i++) if(!outdeg[i] && indeg[i]) leaf[i] = 1;
	for(int i = 1; i <= n; i++){
		if(!leaf[i]){
			int cnt = 0;
			for(int v : con[i]) if(leaf[v]) cnt++;
			if(cnt < 3){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
}