#include <bits/stdc++.h>
#define maxn 100

using namespace std;

int t;
int n, m;
int a[maxn][maxn];
int b[maxn][2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[i][j]);
		memset(b, 0, sizeof(b));
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(i + j - 2 == n + m - (i + j)) continue;
				b[min(i + j - 2, n + m - (i + j))][a[i][j]]++;
			}
		}
		int ans = 0;
		for(int i = 0;i <= n + m - 2;i++) ans += min(b[i][0], b[i][1]);
		printf("%d\n", ans);
	}
}