#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
char s[maxn];


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s);
		int st = -1;
		for(int i = 0;i < n;i++){
			if(s[i] != s[(i + 1) % n]){
				st = (i + 1) % n;
				break;
			}
		}
		if(st == -1) printf("%d", (n + 2) / 3);
		else{
			int len = 0, ans = 0;
			for(int i = 0;i < n;i++){
				int j = (i + st) % n, k = (i - 1 + st + n) % n;
				if(s[j] != s[k]){
					ans += len / 3;
					len = 1;
				}else{
					len++;
				}
			}
			printf("%d", ans + len / 3);
		}
		puts("");
	}
}