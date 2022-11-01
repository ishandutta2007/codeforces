#include <bits/stdc++.h>
#define maxn 55

using namespace std;

int t;
int n;
int a[maxn];
int b[maxn];
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		ans = 0;
		for(int i = 1;i <= n * 2;i++){
			int sum = 0;
			for(int j = 1;j <= n;j++) b[j] = 0;
			for(int j = 1;j <= n;j++) b[a[j]]++;
			for(int j = 1;j <= n;j++){
				if(i - j <= 0 || i - j > n) continue;
				if(i - j == j){
					sum += b[j] / 2;
					b[j] %= 2;
				}else{
					int x = min(b[j], b[i - j]);
					b[j] -= x, b[i - j] -= x;
					sum += x;
				}
				
			}
			ans = max(ans, sum);
		}
		printf("%d\n", ans);
	}
}