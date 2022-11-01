#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int cnt = 0;
		for(int i = 1;i <= n;i++) cnt += s[i] == 'E';
		puts(cnt == n - 1 ? "NO" : "YES");
	}
}