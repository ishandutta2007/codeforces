#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int n;
char s[maxn];
bool a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int x = 0, y = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '<') x = 1;
			if(s[i] == '>') y = 1;
		}
		if(!(x && y)){
			printf("%d\n", n);
			continue;
		}
		for(int i = 1;i <= n;i++) a[i] = false;
		for(int i = 1;i <= n;i++){
			if(s[i] == '-') a[i] = a[i - 1 + (i == 1 ? n : 0)] = true;
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) ans += a[i];
		printf("%d\n", ans);
	}
}