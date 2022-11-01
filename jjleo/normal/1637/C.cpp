#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		if(*max_element(a + 2, a + n) == 1){
			puts("-1");
			continue;
		}
		if(n == 3 && (a[2] & 1)){
			puts("-1");
			continue;
		}
		long long ans = 0;
		for(int i = 2;i < n;i++) ans += (a[i] + 1) / 2 * 2;
		printf("%lld\n", ans / 2);
	}
}