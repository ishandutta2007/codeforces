#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int mk[333][333];
int vis[333][333][31][8];
int n, t[31];

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void mark(int s, int e, int x, int v){
	for(int i=1; i<=x; i++){
		mk[s+dx[v] * i][e + dy[v]*i] = 1;
	}
}

void bktk(int x, int y, int d, int v){
	if(d == n) return;
	if(vis[x][y][d][v]) return;
	vis[x][y][d][v] = 1;
	mark(x, y, t[d], v);
	bktk(x + dx[v] * t[d], y + dy[v] * t[d], d+1, (v+1)%8);
	bktk(x + dx[v] * t[d], y + dy[v] * t[d], d+1, (v+7)%8);
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> t[i];
	bktk(160, 160, 0, 0);
	int cnt = 0;
	for(int i=0; i<333; i++){
		for(int j=0; j<333; j++){
			if(mk[i][j]) cnt++;
		}
	}
	cout << cnt;
}