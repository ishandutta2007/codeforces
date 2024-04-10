#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;

vector<int> con[N];
vector<int> path;
int odd[N], vis[N], parity[N], found;
int currsz = 0;

void dfs(int s, int p, bool root = 1){
	if(odd[s]) found = 1;
	vis[s] = 1;
	path.push_back(s);
	parity[s] ^= 1;
	int cnt = 0;
	for(int v : con[s]){
		cnt++;
		if(!vis[v]){
			dfs(v, s, 0);
			if(parity[v] ^ odd[v]){
				path.push_back(s);
				parity[s] ^= 1;
				path.push_back(v);
				parity[v] ^= 1;
			}
			path.push_back(s);
			parity[s] ^= 1;
		}
	}
	if(root){
		if(parity[s] ^ odd[s]){
			path.resize(path.size() - 1);
			parity[s] ^= 1;
		}
	}
}

int main(){
	int n, m, u, v;
	sd(n);sd(m);
	for(int i = 1; i <= m; i++){
		sd(u); sd(v);
		con[u].pb(v);
		con[v].pb(u);
	}

	for(int i = 1; i <= n; i++){
		sd(odd[i]);
	}

	int cnt = 0;

	for(int i = 1;i <=n; i++){
		if(!vis[i]){
			found = 0;
			dfs(i, 0);
			if(found){
				cnt++;
				if(cnt > 1){
					printf("-1\n");
					return 0;
				}
			}
			else if(!cnt){
				path.clear();
			}
		}
	}
	printf("%d\n", (int)path.size());
	for(int node : path) printf("%d ", node);
}