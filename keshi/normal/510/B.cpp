#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


string s[60];
int n, m;
bool visited[60][60], ans;

bool val(int x, int y, int x1, int y1, char c){
	if(x == x1 && y == y1){
		return 0;
	}
	if(x < 0 || x >= n || y < 0 || y >= m){
		return 0;
	}
	return s[x][y] == c;
}

void dfs(int x, int y, int x2, int y2){
	visited[x][y] = 1;
	int x1, y1;
	x1 = x + 1;
	y1 = y;
	if(val(x1, y1, x2, y2, s[x][y])){
		if(visited[x1][y1]){
			ans = 1;
			return;
		}
		else{
			dfs(x1, y1, x, y);
		}
	}
	x1 = x - 1;
	y1 = y;
	if(val(x1, y1, x2, y2, s[x][y])){
		if(visited[x1][y1]){
			ans = 1;
			return;
		}
		else{
			dfs(x1, y1, x, y);
		}
	}
	x1 = x;
	y1 = y + 1;
	if(val(x1, y1, x2, y2, s[x][y])){
		if(visited[x1][y1]){
			ans = 1;
			return;
		}
		else{
			dfs(x1, y1, x, y);
		}
	}
	x1 = x;
	y1 = y - 1;
	if(val(x1, y1, x2, y2, s[x][y])){
		if(visited[x1][y1]){
			ans = 1;
			return;
		}
		else{
			dfs(x1, y1, x, y);
		}
	}
	return;
}

int main(){
	fast_io;
	int x, y;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(!visited[x][y]){
				dfs(x, y, -1, -1);
			}
		}
	}
	cout << (ans == 1 ? "Yes" : "No");
	return 0;
}