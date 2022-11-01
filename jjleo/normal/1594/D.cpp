#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, m;
vector<pair<int, int> > v[maxn];
int x, y;
char s[100];
int col[maxn];
vector<int> b;
bool g;
int cnt;

void dfs(int i){
	b.push_back(i);
	cnt += col[i];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, co = v[i][j].second;
		if(col[to] == -1) col[to] = col[i] ^ co, dfs(to);
		else if(col[to] != (col[i] ^ co)) g = true;
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), col[i] = -1;
		while(m--){
			scanf("%d%d%s", &x, &y, s);
			v[x].push_back({y, s[0] == 'i'}), v[y].push_back({x, s[0] == 'i'});
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) if(col[i] == -1){
			col[i] = 0;
			g = false, cnt = 0, dfs(i);
			int sum = -1;
			if(!g) sum = cnt;
			while(!b.empty()) col[b.back()] = -1, b.pop_back();
			col[i] = 1;
			g = false, cnt = 0, dfs(i);
			if(!g) sum = max(sum, cnt);
			b.clear();
			if(sum == -1){
				ans = -1;
				break;
			}
			ans += sum;
		}
		printf("%d\n", ans == -1 ? -1 : ans);
	}
}