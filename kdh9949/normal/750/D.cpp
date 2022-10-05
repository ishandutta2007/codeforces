#include <bits/stdc++.h>
using namespace std;

struct go{
	int x, y, d;
};

int n, d[31];
int chk[601][601][8];
vector<go> v, nv;
bool grid[601][601];
int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", d + i);
	d[1]--;
	v.push_back({300, 300, 1});
	for(int i = 1; i <= n; i++){
		for(auto &c : v){
			int nx = c.x + d[i] * dx[c.d];
			int ny = c.y + d[i] * dy[c.d];
			for(int j = 0; j <= d[i]; j++) grid[c.x + j * dx[c.d]][c.y + j * dy[c.d]] = true;
			if(chk[nx][ny][(c.d + 1) % 8] != i){
				chk[nx][ny][(c.d + 1) % 8] = i;
				nv.push_back({nx, ny, (c.d + 1) % 8});
			}
			if(chk[nx][ny][(c.d + 7) % 8] != i){
				chk[nx][ny][(c.d + 7) % 8] = i;
				nv.push_back({nx, ny, (c.d + 7) % 8});
			}
		}
		v.swap(nv);
		vector<go>().swap(nv);
	}
	int ans = 0;
	for(int i = 0; i <= 600; i++) for(int j = 0; j <= 600; j++) ans += grid[i][j];
	printf("%d\n", ans);
	return 0;
}