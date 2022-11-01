#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, q;
bool a[3][maxn], b[3][maxn];
int x, y;
int ans;

inline void update(int x, int y){
	if(a[x][y]){
		if(b[x][y]) b[x][y] = false, --ans;
		for(int i = -1;i <= 1;i++){
			for(int j = -1;j <= 1;j++){
				if(i == 0) continue;
				int xx = x + i, yy = y + j;
				if(xx && xx <= 2 && yy && yy <= n){
					if(a[xx][yy]){
						if(!b[xx][yy]) b[xx][yy] = true, ans++;
						if(!b[x][y]) b[x][y] = true, ans++;
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &q);
	while(q--){
		scanf("%d%d", &x, &y), a[x][y] ^= 1;
		if(!a[x][y]){
			if(b[x][y]){
				b[x][y] = false, ans--;
				for(int i = -1;i <= 1;i++){
					for(int j = -1;j <= 1;j++){
						if(i == 0) continue;
						int xx = x + i, yy = y + j;
						if(xx && xx <= 2 && yy && yy <= n && b[xx][yy]) update(xx, yy);
					}
				} 
			}
		}else{
			update(x, y);
		}
		puts(ans ? "no" : "yes");
	}
}