#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 1e9 + 7;

int T, n, m, s, t;
vector<int> v[maxn];
vector<pair<int, int> > w[maxn][2];
int x, y;
int d[maxn];
int deg[maxn][2], f[maxn][2];

inline void add(pair<int, int> x, pair<int, int> y){
	w[x.first][x.second].push_back(y);
	deg[y.first][y.second]++;
}

queue<int> q;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &n, &m, &s, &t);
		for(int i = 1;i <= n;i++) v[i].clear(), d[i] = 1e9, w[i][0].clear(), w[i][1].clear(), deg[i][0] = deg[i][1] = f[i][0] = f[i][1] = 0;
		while(m--) scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
		q.push(t), d[t] = 0;
		while(!q.empty()){
			int x = q.front();q.pop();
			for(auto to : v[x]){
				if(d[to] == 1e9) d[to] = d[x] + 1, q.push(to);
			}
		}
		for(int i = 1;i <= n;i++) for(auto j : v[i]){
			if(d[j] == d[i] - 1) add({i, 0}, {j, 0}), add({i, 1}, {j, 1});
			if(d[i] == d[j]) add({i, 0}, {j, 1});
		}
		queue<pair<int, int> > q;
		f[s][0] = 1;
		for(int i = 1;i <= n;i++) for(int j = 0;j <= 1;j++) if(deg[i][j] == 0) q.push({i, j});
		while(!q.empty()){
			int x = q.front().first, y = q.front().second;q.pop();
			for(auto to : w[x][y]){
				int i = to.first, j = to.second;
				f[i][j] = (f[i][j] + f[x][y]) % p;
				deg[i][j]--;
				if(deg[i][j] == 0) q.push({i, j});
			}
		}
		printf("%d\n", (f[t][0] + f[t][1]) % p);
	}
}