#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];
int f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int sum = a[n] / 3, ans = 1e9;
		sum = max(0, sum - 1);
		int m = a[n] - sum * 3;
		for(int x = 0;x <= 3;x++) for(int y = 0;y <= 3;y++) for(int z = 0;z <= 3;z++){
			for(int i = 0;i <= m;i++) f[i] = 0;
			f[0] = 1;
			for(int i = m;i;i--){
				for(int j = i - 1;~j;j--){
					if((i - j) % 1 == 0 && (i - j) / 1 <= x) f[i] |= f[j];
				}
			}
			for(int i = m;i;i--){
				for(int j = i - 1;~j;j--){
					if((i - j) % 2 == 0 && (i - j) / 2 <= y) f[i] |= f[j];
				}
			}
			for(int i = m;i;i--){
				for(int j = i - 1;~j;j--){
					if((i - j) % 3 == 0 && (i - j) / 3 <= z) f[i] |= f[j];
				}
			}
			int cnt = 0;
			for(int j = 1;j <= n;j++){
				for(int i = 0;i <= m;i++){
					if((a[j] - i) % 3 == 0 && (a[j] - i) >= 0 && (a[j] - i) / 3 <= sum && f[i]){
						cnt++;
						break;
					}
				}
			}
			if(cnt == n) ans = min(ans, x + y + z);//printf("%d %d %d--\n", x, y, z);
		}
		printf("%d\n", sum + ans);
	}
}