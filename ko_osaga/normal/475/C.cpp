#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, m;
char s[1005][1005];
int a[1005][1005];

int psum(int sx, int ex, int sy, int ey){
	return a[ex][ey] - a[sx-1][ey] - a[ex][sy-1] + a[sx-1][sy-1];
}

bool viable(int x, int y, int w, int h){
	if(x + w - 1 > n || y + h - 1 > m) return 0;
	if(psum(x, x+w-1, y, y+h-1) == w * h) return 1;
	return 0;
}

bool ok(pi p, int x, int y){
	if(!viable(p.first, p.second, x, y)) return 0;
	int cnt = x * y;
	while(1){
		 bool dn = viable(p.first+1, p.second, x, y);
		 bool ri = viable(p.first, p.second+1, x, y);
		 if(dn && ri) return 0;
		 if(!dn && !ri){
		 	 break;
		 }
		 if(dn) p.first++, cnt += y;
		 else p.second++, cnt += x;
	}
	return cnt == a[n][m];
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> (1 + s[i]);
	pi up(-1, -1);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			a[i][j] = (s[i][j] == 'X');
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
			if(up.first == -1){
				if(s[i][j] == 'X'){
					up = pi(i, j);
				}
			}
		}
	}
	int lx = 1, ly = 1;
	while(up.first + lx <= n && s[up.first + lx][up.second] == 'X'){
		lx++;
	}
	while(up.second + ly <= m && s[up.first][up.second + ly] == 'X'){
		ly++;
	}
	int ret = 1e9;
	for(int i=1; i<=lx; i++){
		if(ok(up, i, ly)){
			ret = min(ret, i * ly);
			break;
		}
	}
	for(int i=1; i<=ly; i++){
		if(ok(up, lx, i)){
			ret = min(ret, i * lx);
			break;
		}
	}
	if(ret > 1e8){
		ret = -1;
	}
	cout << ret;
}