#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

int t;
int n;
char s[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		for(int d = 0;d <= 9;d++){
			int ans = 0;
			int l = 1e9, r = 0, u = 1e9, D = 0;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					if(s[i][j] == '0' + d){
						l = min(l, j), r = max(r, j);
						u = min(u, i), D = max(D, i);
					}
				}
			}
			for(int i = 1;i <= n;i++){
				int mn = 1e9, mx = 0;
				for(int j = 1;j <= n;j++){
					if(s[i][j] == '0' + d){
						mn = min(mn, j), mx = max(mx, j);
					}
				}
				if(mx){
					ans = max(ans, (mx - mn) * max(i - 1, n - i));
					if(D) ans = max(ans, max(n - mn, mx - 1) * max(i - u, D - i));
				}
			}
			for(int j = 1;j <= n;j++){
				int mn = 1e9, mx = 0;
				for(int i = 1;i <= n;i++){
					if(s[i][j] == '0' + d){
						mn = min(mn, i), mx = max(mx, i);
					}
				}
				if(mx){
					ans = max(ans, (mx - mn) * max(j - 1, n - j));
					if(r) ans = max(ans, max(n - mn, mx - 1) * max(j - l, r - j));
				}
			}
			printf("%d ", ans);
		}
		puts("");
	}
}