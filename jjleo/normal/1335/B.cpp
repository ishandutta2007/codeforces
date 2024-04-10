#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, a, b;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &a, &b);
		for(int i = 1;i <= a - b + 1;i++) s[i] = 'a';
		for(int i = a - b + 2;i <= a;i++) s[i] = 'a' + i - (a - b + 1);
		for(int i = a + 1;i <= n;i++) s[i] = s[i - a];
		for(int i = 1;i <= n;i++) printf("%c", s[i]);
		puts("");
	}
}