#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char s[maxn];
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		if(s[n] == 'o') puts("FILIPINO");
		else if(s[n] == 'u') puts("JAPANESE");
		else puts("KOREAN");
	}	
}