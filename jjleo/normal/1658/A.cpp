#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int ans = 0;
		for(int i = 2;i <= n;i++){
			if(s[i] == '0' && s[i - 1] == '0') ans += 2;
			if(i >= 3 && s[i] == '0' && s[i - 1] == '1' && s[i - 2] == '0') ans++;
		}
		printf("%d\n", ans);
	}
}