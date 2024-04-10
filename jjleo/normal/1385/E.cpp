#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, m;
vector<int> v[maxn];
vector<pair<int, int> > V;
int a[maxn], b[maxn];
int x, y, z;

queue<int> q;

int deg[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), deg[i] = 0;
		V.clear();
		while(m--){
			scanf("%d%d%d", &x, &y, &z);
			if(x == 1) v[y].push_back(z), deg[z]++;
			else V.push_back({y, z});
		}
		for(int i = 1;i <= n;i++) if(deg[i] == 0) q.push(i);
		bool suc = true;
		for(int i = 1;i <= n;i++){
			if(q.empty()){
				suc = false;
				break;
			}
			a[i] = q.front();q.pop();
			for(int j = 0;j < v[a[i]].size();j++){
				deg[v[a[i]][j]]--;
				if(deg[v[a[i]][j]] == 0) q.push(v[a[i]][j]);
			}
		}
		if(!suc){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 1;i <= n;i++) b[a[i]] = i;
		for(int i = 0;i < V.size();i++){
			if(b[V[i].first] > b[V[i].second]) swap(V[i].first, V[i].second);
			printf("%d %d\n", V[i].first, V[i].second);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < v[i].size();j++){
				printf("%d %d\n", i, v[i][j]);
			}
		}
	} 
}