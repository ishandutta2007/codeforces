#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int t;
int n, k;
int a[maxn][maxn][2];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > q;
int d[maxn][maxn];
bool vis[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 0;i <= k;i++) for(int j = 0;j <= k;j++) a[i][j][0] = a[i][j][1] = 0, d[i][j] = 1e9, vis[i][j] = false;
		for(int i = 1;i <= n;i++){
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if(x1 == x2) a[x1 - 1][min(y1, y2)][1]++;
			else a[min(x1, x2)][y1 - 1][0]++;
		}
		for(int i = 1;i <= k;i++){
			q.push(make_tuple(d[i][0] = 0, i, 0));
			q.push(make_tuple(d[0][i] = 0, 0, i));
		}
		while(!q.empty()){
			int x = get<1>(q.top()), y = get<2>(q.top());q.pop();
			if(vis[x][y]) continue;
			vis[x][y] = true;
			int xx = k - x, yy = k - y;
			if(y + 1 <= k && d[x][y + 1] > d[x][y] + a[x][y][0] + a[xx][yy - 1][0]){
				d[x][y + 1] = d[x][y] + a[x][y][0] + a[xx][yy - 1][0];
				q.push(make_tuple(d[x][y + 1], x, y + 1));
			}
			if(y - 1 >= 0 && d[x][y - 1] > d[x][y] + a[x][y - 1][0] + a[xx][yy][0]){
				d[x][y - 1] = d[x][y] + a[x][y - 1][0] + a[xx][yy][0];
				q.push(make_tuple(d[x][y - 1], x, y - 1));
			}
			if(x + 1 <= k && d[x + 1][y] > d[x][y] + a[x][y][1] + a[xx - 1][yy][1]){
				d[x + 1][y] = d[x][y] + a[x][y][1] + a[xx - 1][yy][1];
				q.push(make_tuple(d[x + 1][y], x + 1, y));
			}
			if(x - 1 >= 0 && d[x - 1][y] > d[x][y] + a[x - 1][y][1] + a[xx][yy][1]){
				d[x - 1][y] = d[x][y] + a[x - 1][y][1] + a[xx][yy][1];
				q.push(make_tuple(d[x - 1][y], x - 1, y));
			}
		} 
		printf("%d\n", n - d[k / 2][k / 2]);
	}
}