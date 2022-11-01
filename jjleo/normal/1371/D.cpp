#include <bits/stdc++.h>
#define maxn 508

using namespace std;

int t;
int n, k;
int a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		memset(a, 0, sizeof(a)); 
		if(k % n) puts("2");
		else puts("0");
		int x = 1;
		for(int i = 1;i <= n;i++){
			int cnt = k / n;
			if(k % n && k % n >= i) cnt++;
			while(cnt--){
				a[i][x] = 1;
				x++;
				if(x > n) x = 1;
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) printf("%d", a[i][j]);
			puts("");
		}
	}
}