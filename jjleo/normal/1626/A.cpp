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
		int cnt[26] = {0};
		for(int i = 1;i <= n;i++) cnt[s[i] - 'a']++;
		for(int i = 0;i < 26;i++){
			if(cnt[i]) printf("%c", i + 'a');
			if(cnt[i] == 2) printf("%c", i + 'a');
		}
		puts("");
	}
}