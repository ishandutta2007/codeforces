#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

char s[maxn];
int n, q;
int nxt[maxn], f[maxn][26];

void add(int i){
	int j = nxt[i - 1];
	if(s[i] == s[j]) j++;
	else{
		j = f[j][s[i] - 'a'];
		if(s[i] == s[j]) j++;
	}
	nxt[i] = j;
	for(int j = 0;j < 26;j++) f[i + 1][j] = f[nxt[i]][j];
	f[i + 1][s[nxt[i]] - 'a'] = nxt[i];
	
//	printf("%d %d--\n", i, nxt[i]);
//	for(int j = 0;j < 26;j++) printf("%d %d--\n", j, f[i + 1][j]);
}

int main(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 1;i < n;i++) add(i);
	scanf("%d", &q);
	while(q--){
		scanf("%s", s + n);
		int m = strlen(s + n);
		for(int i = n;i < n + m;i++){
			add(i);
			printf("%d ", nxt[i]);
		}
		puts("");
	}
}