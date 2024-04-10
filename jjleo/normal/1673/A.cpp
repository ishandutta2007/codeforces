#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		if(n & 1){
			int sum1 = 0, sum2 = 0;
			for(int i = 1;i < n;i++) sum1 += s[i] - 'a' + 1;
			for(int i = 2;i <= n;i++) sum2 += s[i] - 'a' + 1;
			if(sum1 - (s[n] - 'a' + 1) > sum2 - (s[1] - 'a' + 1)){
				printf(sum1 - (s[n] - 'a' + 1) > 0 ? "Alice" : "Bob");
				printf(" %d\n", abs(sum1 - (s[n] - 'a' + 1)));
			}else{
				printf(sum2 - (s[1] - 'a' + 1) > 0 ? "Alice" : "Bob");
				printf(" %d\n", abs(sum2 - (s[1] - 'a' + 1)));
			}
		}else{
			int ans = 0;
			for(int i = 1;i <= n;i++) ans += s[i] - 'a' + 1;
			printf("Alice %d\n", ans);
		}
	}
}