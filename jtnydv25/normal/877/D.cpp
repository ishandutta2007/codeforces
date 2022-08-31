#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

const int N = 1e6 + 20;
int vis[1 << 10][1 << 10], dist[1 << 10][1 << 10];
int a[N], b[N], n, m, k;
bool valid[1 << 10][1 << 10];


void bfs(int x, int y){
	memset(dist, -1, sizeof dist);
	int e = 0;
	a[++e] = x;
	b[e] = y;
	dist[x][y] = 0;
	vis[x][y] = 1;

	for(int r = 1; r <= e; r++){
		int i = a[r], j = b[r];
		int d = dist[i][j];
		for(int i1 = i + 1; i1 <= i + k && i1 <= n; ++i1){
			if(!valid[i1][j] || (dist[i1][j] >= 0 && dist[i1][j] <= d)) break;
			if(!vis[i1][j]){
				vis[i1][j] = 1;
				dist[i1][j] = d + 1;
				a[++e] = i1;
				b[e] = j;
			}
		}

		for(int j1 = j + 1; j1 <= j + k && j1 <= m; ++j1){
			if(!valid[i][j1] || (dist[i][j1] >= 0 && dist[i][j1] <= d)) break;
			if(!vis[i][j1]){
				vis[i][j1] = 1;
				dist[i][j1] = d + 1;
				a[++e] = i;
				b[e] = j1;
			}
		}

		for(int i1 = i - 1; i1 && i1 >= i - k; --i1){
			if(!valid[i1][j] || (dist[i1][j] >= 0 && dist[i1][j] <= d)) break;
			if(!vis[i1][j] && valid[i1][j]){
				vis[i1][j] = 1;
				dist[i1][j] = d + 1;
				a[++e] = i1;
				b[e] = j;
			}
		}

		for(int j1 = j - 1; j1 >= j - k && j1; --j1){
			if(!valid[i][j1] || (dist[i][j1] >= 0 && dist[i][j1] <= d)) break;
			if(!vis[i][j1] && valid[i][j1]){
				vis[i][j1] = 1;
				dist[i][j1] = d + 1;
				a[++e] = i;
				b[e] = j1;
			}
		}
	}
}

char s[1 << 10];
int main(){
	sd(n); sd(m); sd(k);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		for(int j = 1; j <= m; j++)
			if(s[j - 1] == '.')
				valid[i][j] = 1;
	}

	int i, j, x2, y2;
	sd(i); sd(j); sd(x2); sd(y2);
	bfs(i, j);
	printf("%d\n", dist[x2][y2]);
}