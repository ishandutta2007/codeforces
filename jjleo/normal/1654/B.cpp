#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
char s[maxn];
int cnt[26];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 0;i < 26;i++) cnt[i] = 0;
		for(int i = 1;i <= n;i++) cnt[s[i] - 'a']++;
		for(int i = 1;i <= n;i++){
			if(cnt[s[i] - 'a'] == 1){
				for(int j = i;j <= n;j++) printf("%c", s[j]);
				puts("");
				break;
			}
			cnt[s[i] - 'a']--;
		}
	}
}