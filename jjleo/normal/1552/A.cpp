#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn], a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		for(int i = 1;i <= n;i++) a[i] = s[i];
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for(int i = 1;i <= n;i++) ans += a[i] != s[i];
		printf("%d\n", ans);
	}
}