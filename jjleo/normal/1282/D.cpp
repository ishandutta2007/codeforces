#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int x, y, z;
char s[maxn];

int main(){
	puts("a"), fflush(stdout);
	scanf("%d", &x);
	if(!x) return 0;
	n = x + 1;
	if(n > 300){
		for(int i = 1;i < n;i++) printf("b");
		puts(""), fflush(stdout);
		scanf("%d", &x);
		return 0;
	} 
	for(int i = 1;i <= n;i++) printf("a");
	puts(""), fflush(stdout);
	scanf("%d", &x);
	if(!x) return 0;
	if(x == n){
		for(int i = 1;i < n;i++) printf("b");
		puts(""), fflush(stdout);
		scanf("%d", &x);
		return 0;
	}
	for(int i = 1;i < n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j) printf("b");
			else printf("a");
		}
		puts(""), fflush(stdout);
		scanf("%d", &y);
		if(!y) return 0;
		if(y < x) z++, s[i] = 'b';
		else s[i] = 'a';
	}
	if(z == x) s[n] = 'a';
	else s[n] = 'b';
	for(int i = 1;i <= n;i++) printf("%c", s[i]);
	puts(""), fflush(stdout);
	scanf("%d", &x);
}