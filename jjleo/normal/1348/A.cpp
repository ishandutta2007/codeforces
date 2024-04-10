#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int ans = 1 << n;
		for(int i = 1;i <= n / 2 - 1;i++) ans += 1 << i;
		for(int i = n / 2;i < n;i++) ans -= 1 << i;
		printf("%d\n", ans);
	}
}