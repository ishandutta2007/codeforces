#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, r, c, x, y;
int dist[MAXN][MAXN];
char str[MAXN][MAXN];
bool ok(int p, int q){
	return 0 <= p && p < n && 0 <= q && q < m && str[p][q] == '.';
}

struct node{
	int x, y, d;
};

deque<node> dq;

int main(){
	cin >> n >> m >> r >> c >> x >> y;
	r--, c--;
	for(int i=0; i<n; i++) scanf("%s", str[i]);
	dq.push_back({r, c, 0});
	memset(dist, 0x3f, sizeof(dist));
	dist[r][c] = 0;
	while(!dq.empty()){
		auto x = dq.front();
		dq.pop_front();
		if(dist[x.x][x.y] != x.d) continue;
		for(int i=0; i<4; i++){
			int nd = x.d + (i == 1);
			if(!ok(x.x + dx[i], x.y + dy[i])) continue;
			if(dist[x.x + dx[i]][x.y + dy[i]] > nd){
				dist[x.x + dx[i]][x.y + dy[i]] = nd;
				if(i == 1) dq.push_back({x.x + dx[i], x.y + dy[i], nd});
				else dq.push_front({x.x + dx[i], x.y + dy[i], nd});
			}
		}
	}
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!ok(i, j)) continue;
			if(dist[i][j] > y) continue;
			if(c + dist[i][j] - j > x) continue;
			cnt++;
		}
	}
	cout << cnt << endl;
}