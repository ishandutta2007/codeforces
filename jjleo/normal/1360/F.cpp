#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
char s[100][100];

bool check(){
	for(int i = 2;i <= n;i++){
		int x = 0;
		for(int j = 1;j <= m;j++){
			if(s[1][j] != s[i][j]) x++;
		}
		if(x > 1) return false;
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		bool suc = false;
		for(int i = 1;i <= m;i++){
			char c = s[1][i];
			for(int j = 'a';j <= 'z';j++){
				s[1][i] = j;
				if(check()){
					suc = true;
					break;
				}
			}
			if(suc) break;
			s[1][i] = c;
		}
		if(suc) printf("%s", s[1] + 1);
		else printf("-1");
		puts("");
	}
}