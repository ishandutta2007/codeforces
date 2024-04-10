#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];
int sum[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	if(n >= 100) return printf("1"), 0;
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] ^ a[i];
	int ans = 1e9;
	for(int i = 1;i <= n;i++){
		for(int j = i + 2;j <= n;j++){
			for(int k = i;k < j;k++){
				if((sum[k] ^ sum[i - 1]) > (sum[j] ^ sum[k])){
					ans = min(ans, j - i - 1);
				}
			}
		}
	}
	printf("%d", ans == 1e9 ? -1 : ans);
}