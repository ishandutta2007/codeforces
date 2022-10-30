#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		if((n & 1) || s[1] == ')' || s[n] == '(') puts("No");
		else puts("Yes"); 
	}
}