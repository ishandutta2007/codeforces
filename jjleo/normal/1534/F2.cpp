#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

vector<int> v1[maxn];
int sk[maxn], top;
bool ins[maxn], vis[maxn];
int dfn[maxn], low[maxn], cnt;
int col[maxn], tot;

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

int n, m;
string s[maxn];
int a[maxn];
vector<pair<int, int> > v[maxn];
vector<int> v2[maxn], w[maxn];
int id[maxn], l[maxn], r[maxn];
bool del[maxn];
vector<pair<int, int> > b;

void dfs2(int i){
	if(vis[i]) return; 
	vis[i] = true;
	for(int j = 0;j < w[i].size();j++){
		int to = w[i][j];
		dfs2(to);
		if(del[to] || id[to]) del[i] = true;
	}
}

void dfs3(int i){
	if(vis[i]) return; 
	vis[i] = true;
	for(int j = 0;j < v2[i].size();j++){
		int to = v2[i][j];
		if(del[to]) continue;
		dfs3(to);
		l[i] = min(l[i], l[to]), r[i] = max(r[i], r[to]);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) cin >> s[i];
	for(int i = 1;i <= m;i++) scanf("%d", &a[i]);
	int cnt = 0;
	for(int j = 0;j < m;j++){
		for(int i = n;i;i--){
			if(s[i][j] == '#'){
				v[j + 1].push_back({i, ++cnt});
				if(v[j + 1].size() > 1){
					v1[cnt].push_back(cnt - 1);
					if(s[i + 1][j] == '#') v1[cnt - 1].push_back(cnt);
				}
			}
		}
	}
	for(int j = 2;j <= m;j++){
		if(v[j - 1].empty()) continue;
		int x = 0;
		for(int i = 0;i < v[j].size();i++){
			while(x + 1 < v[j - 1].size() && v[j - 1][x + 1].first >= v[j][i].first) x++;
			if(v[j - 1][x].first >= v[j][i].first) v1[v[j][i].second].push_back(v[j - 1][x].second);
		}
	}
	for(int j = 1;j < m;j++){
		if(v[j + 1].empty()) continue;
		int x = 0;
		for(int i = 0;i < v[j].size();i++){
			while(x + 1 < v[j + 1].size() && v[j + 1][x + 1].first >= v[j][i].first) x++;
			if(v[j + 1][x].first >= v[j][i].first) v1[v[j][i].second].push_back(v[j + 1][x].second);
		}
	}
	for(int i = 1;i <= cnt;i++) if(!vis[i]) dfs1(i);
	for(int J = 1;J <= m;J++){
		for(int I = 0;I < v[J].size();I++){
			int i = v[J][I].second;
			for(int j = 0;j < v1[i].size();j++){
				int to = v1[i][j];
				if(col[i] ^ col[to]) v2[col[i]].push_back(col[to]), w[col[to]].push_back(col[i]);
			}
			if(I + 1 == a[J]) id[col[i]] = J;
		}
	}
	for(int i = 1;i <= tot;i++) vis[i] = false;
	for(int i = 1;i <= tot;i++) if(!vis[i]) dfs2(i);
	vector<int> v;
	for(int i = 1;i <= tot;i++){
		l[i] = maxn, r[i] = 0;
		if(del[i] || !id[i]) continue;
		v.push_back(id[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1;i <= tot;i++){
		if(del[i] || !id[i]) continue;
		l[i] = r[i] = lower_bound(v.begin(), v.end(), id[i]) - v.begin() + 1;
	}
	for(int i = 1;i <= tot;i++) vis[i] = false;
	for(int i = 1;i <= tot;i++) if(!vis[i] && !del[i]) dfs3(i);
	for(int i = 1;i <= tot;i++) if(!del[i]) b.push_back({l[i], r[i]});
	sort(b.begin(), b.end());
	int x = -1, mx = 0, now = 0, ans = 0;
	while(now < v.size()){
		while(x + 1 < b.size() && b[x + 1].first <= now + 1) mx = max(mx, b[++x].second);
		now = mx, ans++;
	}
	printf("%d", ans);
}