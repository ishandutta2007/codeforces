#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m, k;
vector<int> v[maxn];
int x, y;
int deg[maxn];
queue<int> q;
bool inq[maxn];
vector<int> ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1;i <= n;i++) v[i].clear(), deg[i] = inq[i] = 0;
		//mp.clear();
		for(int i = 1;i <= m;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
			deg[x]++, deg[y]++;
			//mp[x][y] = mp[y][x] = true;
		}
		if(1ll * k * (k - 1) / 2 > m){
			puts("-1");
			continue;
		}
		for(int i = 1;i <= n;i++) sort(v[i].begin(), v[i].end());
		while(!q.empty()) q.pop();
		for(int i = 1;i <= n;i++) if(deg[i] <= k - 1) q.push(i), inq[i] = true;
		bool suc = false;
		while(!q.empty()){
			int x = q.front();q.pop();
			if(deg[x] == k - 1){
				vector<int> w;
				w.push_back(x);
				for(int i = 0;i < v[x].size();i++){
					int to = v[x][i];
					if(!deg[to]) continue;
					w.push_back(to);
				}
				bool tag = true;
				for(int i = 0;i < w.size() && tag;i++){
					for(int j = 0;j < i && tag;j++){
						tag &= binary_search(v[w[i]].begin(), v[w[i]].end(), w[j]);
					}
				}
				if(tag){
					suc = true;
					puts("2");
					for(int i = 0;i < w.size();i++) printf("%d ", w[i]);
					puts("");
					break;
				}
			}
			for(int i = 0;i < v[x].size();i++){
				int to = v[x][i];
				if(!deg[to]) continue;
				deg[to]--;
				if(deg[to] <= k - 1 && !inq[to]) q.push(to), inq[to] = true;
			}
			deg[x] = 0;
		}
		if(suc) continue;
		ans.clear();
		for(int i = 1;i <= n;i++) if(deg[i]) ans.push_back(i);
		if(ans.empty()) puts("-1");
		else{
			printf("1 %d\n", ans.size());
			for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
			puts("");
		}
	}
	
}