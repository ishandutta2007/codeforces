#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, q;
char s[maxn];
int a[maxn][26];
int l, r;

int main(){
	scanf("%s%d", s + 1, &q);
	n = strlen(s + 1);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 26;j++) a[i][j] += a[i - 1][j];
		a[i][s[i] - 'a']++;
	}
	while(q--){
		scanf("%d%d", &l, &r);
		if(l == r || s[l] != s[r]){
			puts("Yes");
			continue; 
		}
		int cnt = 0;
		for(int i = 0;i < 26;i++) cnt += (a[r][i] - a[l - 1][i]) != 0;
		if(cnt <= 2){
			puts("No");
			continue;
		}
		puts("Yes");
	}
}