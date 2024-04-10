#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		if(n >= 2 && s[1] == s[2]){
			printf("%c%c\n", s[1], s[1]);
			continue;
		}
		int x = n;
		for(int i = 1;i < n;i++){
			if(s[i] < s[i + 1]){
				x = i;
				break;
			}
		}
		for(int i = 1;i <= x;i++) printf("%c", s[i]);
		for(int i = x;i;i--) printf("%c", s[i]);puts("");
	}
}