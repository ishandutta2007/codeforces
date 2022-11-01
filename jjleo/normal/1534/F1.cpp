#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int n, m;
string s[maxn];

vector<int> v1[maxn];
int sk[maxn], top;
bool ins[maxn], vis[maxn];
int dfn[maxn], low[maxn], cnt;
int col[maxn], tot;
int deg[maxn];

void dfs1(int i){
	sk[++top] = i, vis[i] = ins[i] = true;
	dfn[i] = low[i] = ++cnt;
	for(int j = 0;j < v1[i].size();j++){
		int to = v1[i][j];
		if(vis[to]){
			if(ins[to]) low[i] = min(low[i], low[to]);
		}else{
			dfs1(to);
			low[i] = min(low[i], low[to]);
		}
	} 
	if(dfn[i] == low[i]){
		col[i] = ++tot;
		while(1){
			int x = sk[top--];
			ins[x] = false;
			if(x == i) break;
			col[x] = col[i];
		}
	}
} 

struct Node{
	int l, r, id;
};

vector<Node> v[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) cin >> s[i];
	int cnt = 0;
	for(int j = 0;j < m;j++){
		int last = 0, now;
		for(int i = 1;i <= n;i++){
			if(s[i][j] == '#'){
				if(i == 1 || s[i - 1][j] != '#'){
					if(last) v[j + 1].push_back((Node){last, now, ++cnt});
					last = i;
				}
				now = i;
			}
		}
		if(last) v[j + 1].push_back((Node){last, now, ++cnt});
	}
	for(int i = 1;i <= m;i++) for(int j = 1;j < v[i].size();j++) v1[v[i][j - 1].id].push_back(v[i][j].id);
	for(int i = 2;i <= m;i++){
		int x = 0;
		if(v[i - 1].empty()) continue;
		for(int j = 0;j < v[i].size();j++){
			while(x + 1 < v[i - 1].size() && v[i - 1][x].r < v[i][j].l) x++;
			if(v[i - 1][x].r < v[i][j].l) break;
			v1[v[i][j].id].push_back(v[i - 1][x].id);
		}
	}
	for(int i = 1;i < m;i++){
		int x = 0;
		if(v[i + 1].empty()) continue;
		for(int j = 0;j < v[i].size();j++){
			while(x + 1 < v[i + 1].size() && v[i + 1][x].r < v[i][j].l) x++;
			if(v[i + 1][x].r < v[i][j].l) break;
			v1[v[i][j].id].push_back(v[i + 1][x].id);
		}
	}
	for(int i = 1;i <= cnt;i++) if(!vis[i]) dfs1(i); 
	for(int i = 1;i <= cnt;i++){
		for(int j = 0;j < v1[i].size();j++){
			int to = v1[i][j];
			if(col[i] ^ col[to]) deg[col[to]]++;
		}
	}
	int ans = 0;
	for(int i = 1;i <= tot;i++) ans += deg[i] == 0;
	printf("%d", ans);
}