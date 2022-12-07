#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, q;
char s[maxn];
char c[10];
int x;

int check(int i){
	if(i < 1 || i + 2 > n) return 0;
	return s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c';
}

int main(){
	scanf("%d%d%s", &n, &q, s + 1);
	int ans = 0;
	for(int i = 1;i + 2 <= n;i++) ans += check(i);
	while(q--){
		scanf("%d%s", &x, c);
		for(int j = x - 2;j <= x + 2;j++) ans -= check(j);
		s[x] = c[0];
		for(int j = x - 2;j <= x + 2;j++) ans += check(j);
		printf("%d\n", ans);
	}
}