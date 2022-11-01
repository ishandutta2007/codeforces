#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, a, b;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%s", &n, &a, &b, s + 1);
		if(b > 0){
			printf("%d\n", (a + b) * n);
			continue;
		}
		int cnt = 0; 
		for(int i = 1;i <= n;i++) cnt += s[i] != s[i - 1];
		printf("%d\n", a * n + (cnt + 2) / 2 * b);
	}
}