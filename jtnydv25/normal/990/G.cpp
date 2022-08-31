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
vector<int> con[N];
vector<int> pos[N];
int a[N], b[N], val[N];
long long F[N], G[N];

int vis[N];
int cnt = 0;
void dfs(int s, int d){
	vis[s] = d;
	cnt++;
	for(int v : con[s]){
		if(vis[v] != d && val[v] % d == 0){
			dfs(v, d);
		}
	}
}

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(val[i]);
		pos[val[i]].push_back(i);
	}

	for(int i = 1; i < n; i++){
		sd(a[i]); sd(b[i]);
		con[a[i]].push_back(b[i]);
		con[b[i]].push_back(a[i]);
	}

	for(int d = N - 1; d >= 1; d--){
		cnt = 0;
		for(int v = d; v < N; v += d){
			for(int s : pos[v]){
				if(vis[s] != d){
					cnt = 0;
					dfs(s, d);
					G[d] += (cnt * 1ll * (cnt + 1)) / 2;
				}	
			}
		}
		F[d] = G[d];
		for(int d2 = 2 * d; d2 < N; d2 += d) F[d] -= F[d2];
	}

	for(int i = 1; i < N; i++)
		if(F[i]){
			printf("%d %lld\n", i, F[i]);
		}
}