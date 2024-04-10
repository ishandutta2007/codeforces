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

const int N = 55;
vector<int> con[N + N];

vector<int> vertices;
void add_edge(int i, int j){
	j += N;
	con[i].push_back(j);
	con[j].push_back(i);
}

int vis[N + N];

void dfs(int s){
	vertices.push_back(s);
	vis[s] = 1;
	for(int v : con[s]) if(!vis[v]) dfs(v);
}

string s[N];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] ="."+s[i];
		for(int j = 1; j <= m; j++){
			if(s[i][j] == '#') add_edge(i, j);
		}
	}
	for(int i = 1; i <= N + m; i++) if(!vis[i]){
		vertices.clear();
		dfs(i);
		for(int j : vertices){
			for(int k : vertices){
				if(j <= n && k > N && s[j][k - N] != '#'){
					cout << "No"; return 0;
				}
			}
		}
	}
	cout << "Yes";
}