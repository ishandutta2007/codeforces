#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int t;
int n, m;
char s[maxn][maxn];
int a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				a[i][j] = 0;
				for(int k = 1;;k++){
					if(j - k + 1 <= 0 || j + k - 1 > m) break;
					if(s[i][j - k + 1] == '.' || s[i][j + k - 1] == '.') break;
					a[i][j] = k;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				for(int k = 1;;k++){
					if(i + k - 1 > n) break;
					if(a[i + k - 1][j] < k) break;
					ans++;
				}
			} 
		} 
		printf("%d\n", ans);
	}
}