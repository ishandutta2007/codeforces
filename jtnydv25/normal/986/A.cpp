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
int dist[N], a[N];
const int INF = 1e9;

vector<int> ms[N];
int main(){
	int n, m, s, k;
	sd(n); sd(m); sd(k); sd(s);
	for(int i = 1; i <= n; i++) sd(a[i]);
	for(int i = 1; i <= m; i++){
		int u, v;
		sd(u); sd(v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++) dist[j] = INF;
		queue<int> q;

		for(int j = 1; j <= n; j++){
			if(a[j] == i) q.push(j), dist[j] = 0;
		}
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int v : con[u]) if(dist[v] == INF){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		
		for(int j = 1; j <= n; j++) ms[j].push_back(dist[j]);
	}
	for(int i = 1; i <= n; i++){
		sort(ms[i].begin(), ms[i].end());
		long long x = 0;
		for(int j = 1; j <= s; j++){
			x += ms[i][j - 1];
		}
		printf("%lld ", x);
	}
}