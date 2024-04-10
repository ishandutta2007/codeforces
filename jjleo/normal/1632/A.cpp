#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn]; 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		if(n == 2 && s[1] == s[2]) puts("NO");
		else puts(n <= 2 ? "YES" : "NO");
	}
}