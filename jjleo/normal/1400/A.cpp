#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		for(int i = 1;i <= n;i++) printf("%c", s[2 * i - 1]);
		puts("");
	}
}