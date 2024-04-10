#include <bits/stdc++.h>
#define maxn 150086

using namespace std;

int t;
int n;
char s[maxn];
int ans[maxn], cnt;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		cnt = 0;
		for(int i = 1;i <= n;i++){
			if(i + 4 <= n && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e'){
				ans[++cnt] = i + 2;
				i += 4;
				continue;
			}
			if(i + 2 <= n && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e'){
				ans[++cnt] = i + 1;
				i += 2;
				continue;
			}
			if(i + 2 <= n && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o'){
				ans[++cnt] = i + 1;
				i += 2;
				continue;
			}
		}
		printf("%d\n", cnt);
		for(int i = 1;i <= cnt;i++) printf("%d ", ans[i]);
		puts("");
	}
}