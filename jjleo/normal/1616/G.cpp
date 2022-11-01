#include <bits/stdc++.h>
#define maxn 150086

using namespace std;

int t, n, m;
vector<int> v[maxn];
int x, y;
int a[maxn];
vector<int> w[maxn * 2], W[maxn * 2];
bool vis1[maxn * 2], vis2[maxn * 2], Vis1[maxn * 2], Vis2[maxn * 2];

inline void add(int x, int y){
	w[x].push_back(y), W[y].push_back(x);
}

void dfs(int i, vector<int> *w, bool *vis){
	if(vis[i]) return;
	vis[i] = true;
	for(int j = 0;j < w[i].size();j++){
		int to = w[i][j];
		dfs(to, w, vis);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m), n += 2;
		for(int i = 1;i <= n;i++) v[i].clear(), a[i] = 0;
		int cnt = 0;
		while(m--){
			scanf("%d%d", &x, &y), x++, y++;
			v[x].push_back(y);
			if(x + 1 == y) cnt++, a[x] = 1;
		}
		cnt += 2, a[1] = a[n - 1] = 1;
		for(int i = 2;i < n;i++) v[1].push_back(i), v[i].push_back(n);
		if(cnt == n - 1){
			printf("%lld\n", 1ll * (n - 2) * (n - 3) / 2);
			continue;
		}
		for(int i = 1;i <= n;i++) a[i] += a[i - 1];
		for(int i = 1;i <= n * 2;i++) w[i].clear(), W[i].clear(), vis1[i] = vis2[i] = Vis1[i] = Vis2[i] = false; 
		for(int i = 1;i < n;i++){
			for(int j = 0;j < v[i].size();j++){
				int to = v[i][j];
				if(to > i + 1 && a[to - 2] - a[i] == to - 2 - i) add(i, to - 1 + n), add(i + n, to - 1);
			}
		}
		for(int i = 1;i < n;i++) if(a[i] == a[i - 1]){
			x = i;
			break;
		}
		dfs(x, w, vis1), dfs(x, W, Vis1);
		dfs(x + n, w, vis2), dfs(x + n, W, Vis2);
		long long ans = 0, sum1 = 0, sum2 = 0;
		for(int i = 1;i < n;i++){
			if(Vis1[i]) sum1++;
			if(a[i] == a[i - 1]) break;
		}
		for(int i = n - 1;i;i--){
			if(vis1[i]) sum2++;
			if(a[i] == a[i - 1]) break;
		}
		ans += sum1 * sum2;
		sum1 = 0, sum2 = 0;
		for(int i = 1;i < n;i++){
			if(Vis2[i]) sum1++;
			if(a[i] == a[i - 1]) break;
		}
		for(int i = n - 1;i;i--){
			if(vis2[i]) sum2++;
			if(a[i] == a[i - 1]) break;
		}
		ans += sum1 * sum2;
		sum1 = 0, sum2 = 0;
		for(int i = 1;i < n;i++){
			if(Vis1[i] && Vis2[i]) sum1++;
			if(a[i] == a[i - 1]) break;
		}
		for(int i = n - 1;i;i--){
			if(vis1[i] && vis2[i]) sum2++;
			if(a[i] == a[i - 1]) break;
		}
		ans -= sum1 * sum2;
		if(cnt + 1 == n - 1) ans--; 
		printf("%lld\n", ans);
	}
}
/*
1
4 3
1 2
3 4
1 4
*/