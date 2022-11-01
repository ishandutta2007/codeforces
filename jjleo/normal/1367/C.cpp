#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int t;
int n, k;
char s[maxn];
int sum[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		if(n == 1 && s[1] == '1'){
			puts("0");
			continue;
		}
		for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + s[i] - '0';
		for(int i = n + 1;i <= n + k;i++) sum[i] = sum[i - 1];
		if(!sum[n]){
			printf("%d\n", 1 + (n - 1) / (k + 1));
			continue;
		}
		int ans = 0;
		int last = -maxn;
		for(int i = 1;i <= n;i++){
			if(s[i] == '1'){
				last = i;
			}else if(i - last > k && sum[i + k] - sum[i] == 0){
				last = i;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}