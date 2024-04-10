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
		int ans = 0;
		for(int i = 2;i <= n;i++){
			if(s[i] == s[i - 1]){
				if(i < n && s[i] == s[i + 1]){
					ans += 2;
					s[i] = s[i + 1] = 0;
					i++;
				}else ans++, s[i] = 0;
				continue;
			}
			if(i - 2 && s[i] == s[i - 2]){
				ans++;
				s[i] = 0;
			}
		}
		printf("%d\n", ans);
	}
}