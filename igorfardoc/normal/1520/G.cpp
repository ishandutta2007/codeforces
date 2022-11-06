#include<bits/stdc++.h>
#define INF 1000000000
#define MAX 2000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int a[MAX][MAX];
vvi dist1(MAX, vi(MAX, INF)), dist2(MAX, vi(MAX, INF));
int n, m, w;

void bfs(int x, int y, vvi& dist) {
	queue<pair<int, int>> q;
	dist[x][y] = 0;
	q.push({x, y});
	while(!q.empty()) {
		auto p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		for(int dx = -1; dx <= 1; dx++) {
			for(int dy = -1; dy <= 1; dy++) {
				if(abs(dx) + abs(dy) != 1) {
					continue;
				}
				int i = x + dx;
				int j = y + dy;
				if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] == -1) {
					continue;
				}
				if(dist[i][j] == INF) {
					dist[i][j] = dist[x][y] + 1;
					q.push({i, j});
				}
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m >> w;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    bfs(0, 0, dist1);
    bfs(n - 1, m - 1, dist2);
    ll res = 1000000000000000000ll;
    if(dist1[n - 1][m - 1] != INF) {
    	res = min(res, (ll)dist1[n - 1][m - 1] * w);
    }
    if(dist2[0][0] != INF) {
    	res = min(res, (ll)dist2[0][0] * w);
    }
    ll min1 = 1000000000000000000ll;
    ll min2 = min1;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		if(a[i][j] > 0) {
    			if(dist1[i][j] != INF) {
    				min1 = min(min1, (ll)dist1[i][j] * w + a[i][j]);
    			}
    			if(dist2[i][j] != INF) {
    				min2 = min(min2, (ll)dist2[i][j] * w + a[i][j]);
    			}
    		}
    	}
    }
    res = min(res, min1 + min2);
    if(res < 1000000000000000000ll) {
		cout << res;
	} else {
		cout << "-1";
	}
}