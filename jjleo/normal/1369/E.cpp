#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

int n, m;
int w[maxn];
pair<int, int> p[maxn];
queue<int> q;
vector<int> v[maxn];
bool a[maxn], b[maxn];
int ans[maxn], cnt;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &w[i]);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &p[i].first, &p[i].second);
		w[p[i].first]--, w[p[i].second]--;
		v[p[i].first].push_back(i), v[p[i].second].push_back(i);
	}
	for(int i = 1;i <= n;i++) if(w[i] >= 0) a[i] = true, q.push(i);
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int i = 0;i < v[x].size();i++){
			int y = v[x][i];
			if(b[y]) continue;
			b[y] = true, ans[++cnt] = y;
			w[p[y].first]++, w[p[y].second]++;
			if(!a[p[y].first] && w[p[y].first] >= 0) a[p[y].first] = true, q.push(p[y].first);
			if(!a[p[y].second] && w[p[y].second] >= 0) a[p[y].second] = true, q.push(p[y].second);
		}
	}
	if(cnt < m) return printf("DEAD"), 0;
	puts("ALIVE");
	for(int i = cnt;i;i--) printf("%d ", ans[i]);
}