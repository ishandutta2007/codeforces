#include <bits/stdc++.h>
#define maxn 5086

typedef long long ll;

using namespace std;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int n;

bool vis[45][750], mp[45][750];
int x[4] = {0, 0, 1, -1}, y[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;

bool bfs(){
	while(!q.empty()) q.pop();
	q.push({0, 0});
	while(!q.empty()){
		pair<int, int> tp = q.front();q.pop();
		if(tp.first >= 40) {return 1;
		}
		if(vis[tp.first][tp.second]) continue;
		vis[tp.first][tp.second] = 1;
		int X = tp.first, Y = tp.second;
		for(int i = 0; i < 4; i++){
			int xx = X + x[i], yy = Y + y[i];
			if(xx < 0) continue;
			yy = (yy + 720) % 720;
			if(mp[xx][yy]) continue;
			q.push({xx, yy});
		}
	}
	return 0;
}

int main(){
	int t = read();
	while(t--){
		n = read();
		memset(vis, 0, sizeof(vis));
		memset(mp, 0, sizeof(mp));
		for(int i = 1; i <= n; i++){
			char s[5];
			scanf("%s", s + 1);
			if(s[1] == 'C'){
				int r = read() * 2, t1 = read() * 2, t2 = read() * 2;
				for(int j = t1; j != t2 + 1; j = (j + 1) % 720){
					mp[r][j] = 1;
				}
			}
			else{
				int r1 = read() * 2, r2 = read() * 2, t1 = read() * 2;
				for(int j = r1; j <= r2; j++){
					mp[j][t1] = 1;
				}
			}
		}
		puts(bfs() ? "YES" : "NO");
	}
}