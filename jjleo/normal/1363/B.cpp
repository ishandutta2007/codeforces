#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char s[maxn];
int sum[maxn];
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + s[i] - '0';
		ans = min(sum[n], n - sum[n]);
		for(int i = 1;i < n;i++){
			ans = min(ans, min(sum[i] + n - i - (sum[n] - sum[i]), i - sum[i] + sum[n] - sum[i]));
		}
		printf("%d\n", ans);
	} 
}