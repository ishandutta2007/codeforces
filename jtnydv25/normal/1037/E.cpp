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
const int N = 200005;
int deg[N];
set<int> con[N];
int x[N], y[N];
bool there[N];
bool done[N];
set<pii> st;
int val[N];
int main(){
	int n, m, k; sd(n); sd(m);sd(k);
	for(int i = 1; i <= m; i++){
		sd(x[i]); sd(y[i]);
		con[x[i]].insert(y[i]);
		con[y[i]].insert(x[i]);
		deg[x[i]]++;
		deg[y[i]]++;
	}

	for(int i = 1; i <= n; i++) st.insert({deg[i], i});
	while(!st.empty()){
		int u = st.begin()->S;
		// trace(u, deg[u]);
		if(deg[u] < k){
			for(int v : con[u]) if(!done[v]){
				st.erase({deg[v], v});
				deg[v]--;
				st.insert({deg[v], v});
			}
		} else break;
		// trace(u);
		done[u] = 1;
		st.erase({deg[u], u});
	}

	for(int i = m; i >= 1; i--){
		val[i] = st.size();
		if(done[x[i]] || done[y[i]]) continue;

		st.erase({deg[x[i]], x[i]});
		st.erase({deg[y[i]], y[i]});
		deg[x[i]]--;
		deg[y[i]]--;
		st.insert({deg[x[i]], x[i]});
		st.insert({deg[y[i]], y[i]});

		con[x[i]].erase(y[i]);
		con[y[i]].erase(x[i]);

		while(!st.empty()){
			int u = st.begin()->S;
			if(deg[u] < k){
				for(int v : con[u]) if(!done[v]){
					st.erase({deg[v], v});
					deg[v]--;
					st.insert({deg[v], v});
				}
			} else break;
			// trace(u);
			done[u] = 1;
			st.erase({deg[u], u});
		}
	}

	for(int i = 1; i <= m; i++) printf("%d\n", val[i]); 
}