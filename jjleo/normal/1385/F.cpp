#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, k;
int x, y;
vector<int> v[maxn];
int val[maxn];
/*int rt;
int fa[maxn], , siz[maxn];

void dfs(int i){
	bool tag = false;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i]) continue;
		tag = true;
		fa[to] = i;
		dfs(to);
	}
	if(!fa[i]) return;
	if(!tag) val[fa[i]]++;
	else siz[fa[i]]++;
}*/

int ans;
queue<int> q;
set<int> st[maxn]; 
bool inq[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		while(!q.empty()) q.pop();
		for(int i = 1;i <= n;i++) v[i].clear(), val[i] = inq[i] = 0, st[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		if(n == 2){
			puts("1");
			continue;
		}
		for(int i = 1;i <= n;i++){
			if(v[i].size() == 1){
				val[v[i][0]]++;
			}else{
				for(int j = 0;j < v[i].size();j++){
					int to = v[i][j];
					if(v[to].size() ^ 1) st[i].insert(to);
				}
			}
		}
		/*for(int i = 1;i <= n;i++) if(v[i].size() ^ 1) rt = i;
		fa[rt] = 0, dfs(rt);*/
		ans = 0;
		for(int i = 1;i <= n;i++) if(val[i] >= k) q.push(i), inq[i] = true;
		while(!q.empty()){
			int x = q.front();
			q.pop(), inq[x] = false;
			ans += val[x] / k, val[x] %= k;
			if(val[x] == 0 && st[x].size() == 1){
				int y = *st[x].begin();
				st[y].erase(x), val[y]++;
				if(val[y] >= k && !inq[y]) q.push(y), inq[y] = true;
			}
		}
		printf("%d\n", ans);
	}
}