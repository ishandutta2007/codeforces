#include <bits/stdc++.h>
#define maxn 305

using namespace std;

int t, n, m;
int a[maxn][maxn], b[maxn][maxn];

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		bool tag = false;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++){
			scanf("%d", &a[i][j]);
			b[i][j] = 0;
			for(int k = 0;k < 4;k++){
				int ii = i + dx[k], jj = j + dy[k];
				if(ii >= 1 && ii <= n && jj >= 1 && jj <= m) b[i][j]++;
			}
			if(a[i][j] > b[i][j]) tag = true;
		}
		if(tag){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++) printf("%d ", b[i][j]);
			puts("");
		}
	}
}